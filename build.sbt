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
    libraryDependencies += "org.scalactic" %% "scalactic" % "3.2.19",
    libraryDependencies += "org.scalatest" %% "scalatest" % "3.2.19" % "test",
    libraryDependencies += "org.scala-lang" %% "scala3-compiler" % scalaVersion.value % Test,
    libraryDependencies += "org.scalameta" %% "munit" % "1.3.2" % Test,

    Test / fork := true,

    // Speculative inlines a whole speculation window into the function it
    // opened in, and ELMS elaborates a function body by recursing once per
    // statement. `src/test/fact/salsa20.o` has a window 1696 statements long,
    // which is more than the default 1MB stack holds. The other three models
    // emit nothing longer than a hundred lines and want none of this.
    Test / javaOptions += "-Xss16m",

    Test / javaOptions += {
      val conv = fileConverter.value
      val cp = (Test / fullClasspath).value
        .map(e => conv.toPath(e.data))
        .mkString(java.io.File.pathSeparator)
      s"-Dgenerated.test.classpath=$cp"
    }
  )
