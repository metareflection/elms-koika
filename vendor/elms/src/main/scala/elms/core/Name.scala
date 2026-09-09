package elms.core

sealed abstract class Name {
  def render(prefix: String): String
}

private case class Named(s: String) extends Name {
  override def render(prefix: String): String = s
}
private case class Fresh(id: Int) extends Name {
  override def render(prefix: String): String = s"$prefix$id"
}

object Name {
  def from(s: String): Name = Named(s)
  def from(i: Int): Name = Fresh(i)

  // Extraction breaks cost ties on the node ordering, and a node's payload is a
  // `Name`, so this is what decides between two equally small terms.
  given Ordering[Name] = Ordering.by[Name, (Int, String, Int)] {
    case Named(s) => (0, s, 0)
    case Fresh(i) => (1, "", i)
  }
}
