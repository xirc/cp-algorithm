object Main extends App {
  val exp = scala.io.StdIn.readLine()
  val terms = exp.split('+')
  val ans = terms.map { term =>
    val hasZero = term.split('*').map(_.toInt).exists(_ == 0)
    if (hasZero) 0 else 1
  }.sum
  println(ans)
}