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

    // Speculative inlines a whole speculation window into the function it
    // opened in, and ELMS elaborates a function body by recursing once per
    // statement. `src/test/fact/salsa20.o` has a window 1696 statements long,
    // which is more than the default 1MB stack holds. Forwarding extends
    // Speculative and inherits that window, so it wants this too; naive, cache
    // and predictive emit nothing longer than a hundred lines and want none of
    // it.
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
