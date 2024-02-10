package map

fun main() {

    val test = hashMapOf<Int, Int>();
    test[1] = 0;

    val immutable = mapOf(1 to "one", 2 to "two")
    val mutable = mutableMapOf(1 to "one");

    mutable[1] = "meow"
    mutable.put(1, "cat")

    val iskeyIn = 1 in mutable
    val isValIn = mutable.containsValue("Two")
    // immtable[1] = 5  illegal


    mutable.remove(1)

    for ((k, v) in mutable) {
        println(k)
    }

    for (key in mutable.keys) {

    }

    for (value in mutable.values) {

    }

    mutable.isEmpty()
    // can merge maps
    val merged = mutable + immutable

    // get or default
    mutable.getOrElse(4){"unknown"}

    mutable.clear()
}

class MapPractice {
}