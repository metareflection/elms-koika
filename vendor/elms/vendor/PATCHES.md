# Local changes to vendored code

Everything under `vendor/` is a verbatim copy of upstream apart from what is
listed here. Each change is marked in the source with `ELMS-LOCAL PATCH`, so
`grep -rn "ELMS-LOCAL PATCH" vendor/` finds them all. Re-vendoring drops them,
so re-apply from this list.

## foresight, `aca05839`

### `AnalysisMetadata.onUnionMany` never notified the users of a merged class

`readonly/AnalysisUpdater.scala`, `mutable/AnalysisMetadata.scala`,
`immutable/AnalysisMetadata.scala`.

After merging an equivalence group, `onUnionMany` wrote the joined result back
with `updater.update`, which does nothing when the representative already holds
that value. A union changes which nodes a class contains whether or not the
joined result moves, so the absorbed classes' users were left holding results
computed against the pre-union graph and no worklist entry was ever queued for
them.

For `ExtractionAnalysis` that means a parent keeps extracting a term built from
its child's old, worse candidate. Three lines reproduce it:

```scala
val one = graph.add(...Const(1)...)
val inner = graph.add(...Plus(one, one)...)   // best tree: 1 + 1, cost 3
val term = graph.add(...Plus(x, inner)...)    // best tree: x + (1 + 1), cost 5
graph.unionMany(Seq((inner, graph.add(...Const(2)...))))
// inner now extracts as `2`, but `term` still extracts as `x + (1 + 1)`
```

The patch adds `AnalysisUpdater.unioned`, which is `update` without the
short-circuit, and calls it from both `onUnionMany`s.

### `BackoffRuleApplication` was locked to immutable e-graphs

`saturation/BackoffRuleApplication.scala`.

The class was bounded `EGraphT <: EGraphLike[NodeT, EGraphT] with EGraph[NodeT]`
even though its body only calls `searchAndApply.search` and `searchAndApply.apply`,
neither of which needs an immutable graph. `MaximalRuleApplication` already carries
the weaker `readonly.EGraph[NodeT]` bound and ships a `.mutable` factory; this one
did not, so the only scheduling strategy available on the mutable path was
maximal application.

The patch weakens the bound on the class and on the four-argument `apply`, and
adds a `mutable` factory mirroring `MaximalRuleApplication.mutable`.
