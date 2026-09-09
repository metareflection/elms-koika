ThisBuild / scalaVersion := "3.6.4"

// Vendored under `vendor/`, so ELMS's own compiler builds it from source. The
// base directory is the inner `foresight/` and not the checkout root: sbt reads
// any `build.sbt` sitting in a project's base directory, and foresight's own
// would come along with it.
lazy val foresight = (project in file("vendor/foresight/foresight"))
  .settings(
    Compile / unmanagedSourceDirectories := {
      val base = baseDirectory.value / "src" / "main"
      Seq(base / "scala", base / "scala-2.13+", base / "scala-3")
    },
    Compile / unmanagedResourceDirectories := Nil,

    // Foresight's own flags, copied from its `case Some((3, 4))` branch. Its
    // sources are Scala-2-compatible and would not survive ELMS's.
    scalacOptions := Seq(
      "-unchecked",
      "-deprecation",
      "-feature",
      "-Wconf:msg=with as a type operator has been deprecated:silent",
      "-Wconf:msg=is deprecated for wildcard arguments:silent",
      "-Wconf:msg=no longer supported:silent",
      "-Wconf:msg=is more specialized than the right hand side:silent"
    ),
    libraryDependencies ++= Seq(
      "org.scala-lang.modules" %% "scala-xml" % "2.1.0",
      "org.scala-lang.modules" %% "scala-collection-compat" % "2.13.0",
      "org.scala-lang.modules" %% "scala-parallel-collections" % "1.0.4",
      "it.unimi.dsi" % "fastutil" % "8.5.13"
    )
  )

lazy val elms = (project in file("."))
  .dependsOn(foresight)
  .settings(
    name := "elms",
    scalacOptions ++= Seq("-experimental"),
    scalacOptions ++= Seq("-Wconf:msg=match may not be exhaustive:e"),
    scalacOptions ++= Seq("-language:strictEquality"),
    scalacOptions ++= Seq("-feature", "-deprecation"),
    libraryDependencies += "org.scala-lang" %% "scala3-compiler" % scalaVersion.value,
    libraryDependencies += "org.scalactic" %% "scalactic" % "3.2.19",
    libraryDependencies += "org.scalatest" %% "scalatest" % "3.2.19" % "test",
    libraryDependencies += "org.scala-lang" %% "scala3-compiler" % scalaVersion.value % Test,
    Test / fork := true,
    Test / javaOptions += {
      val conv = fileConverter.value
      val cp = (Test / fullClasspath).value
        .map(e => conv.toPath(e.data))
        .mkString(java.io.File.pathSeparator)
      s"-Dgenerated.test.classpath=$cp"
    }
  )
