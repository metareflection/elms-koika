package elms.helpers

import elms.core._

trait DslOps
    extends elms.helpers.poly.DslOps
    with Base
    with Builtins
    with PrimitiveOps
    with VarOps
    with BooleanOps
    with EqualityOps
    with IntegerOps
    with RangeOps
    with StringOps
    with ArrayOps
    with StructOps
