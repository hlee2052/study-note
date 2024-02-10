package set

fun main() {

    val immutable: Set<Int> = setOf(1,2, 3)

    val mutable = mutableSetOf(1, 2, 3)

    // add
    mutable.add(1)

    //remove
    var bool = mutable.remove(1)
    println(bool)

    var boolFalse = mutable.remove(10)
    println(boolFalse)

    var isInSet = 999 in mutable;
    var size = mutable.size

    var isEmpty = mutable.isEmpty()

    var list: List<Int> = immutable.toList()



}




class SetPractice {
}