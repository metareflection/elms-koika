val scala3Version = "3.6.4"

lazy val elms = project.in(file("vendor/elms"))

lazy val root = project
  .in(file("."))
  .dependsOn(elms)
  .settings(
    name := "elms-koika",
    version := "0.1.0-SNAPSHOT",

    scalaVersion := scala3Version,

    scalacOptions ++= Seq("-experimental"),
    scalacOptions ++= Seq("-Wconf:msg=match may not be exhaustive:e"),
    scalacOptions ++= Seq("-language:strictEquality"),
    scalacOptions ++= Seq("-feature", "-deprecation"),

    libraryDependencies += "org.scala-lang" %% "scala3-compiler" % scalaVersion.value,
    libraryDependencies += "org.scalactic" %% "scalactic" % "3.2.20",
    libraryDependencies += "org.scalatest" %% "scalatest" % "3.2.20" % "test",
    libraryDependencies += "org.scala-lang" %% "scala3-compiler" % scalaVersion.value % Test,
    libraryDependencies += "org.scalameta" %% "munit" % "1.3.6" % Test,

    Test / fork := true,

    // Forwarding inlines a store window into the function that opened it, and
    // ELMS elaborates a function body by recursing once per statement.
    // `src/test/fact/salsa20.o` has thirty-eight stores and its longest slot
    // comes out at 986 statements, against 260 for every model that inlines
    // nothing. That fits the default 1MB stack, where the 1696-statement branch
    // window this model used to inherit did not, so this is margin rather than
    // a requirement. Kept as margin: the number is a property of one demo and
    // the next demo is free to be longer.
    Test / javaOptions += "-Xss16m",

    // `.jvmopts` silences the JDK 24 sun.misc.Unsafe warning for sbt's own
    // JVM, but the tests fork, and scala3-library's `LazyVals` reaches for
    // Unsafe again on the way up. Same warning, second JVM, so it needs saying
    // twice.
    Test / javaOptions += "--sun-misc-unsafe-memory-access=allow",

    Test / javaOptions += {
      val conv = fileConverter.value
      val cp = (Test / fullClasspath).value
        .map(e => conv.toPath(e.data))
        .mkString(java.io.File.pathSeparator)
      s"-Dgenerated.test.classpath=$cp"
    }
  )
