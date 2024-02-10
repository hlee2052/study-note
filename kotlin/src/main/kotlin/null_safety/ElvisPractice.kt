package null_safety

fun main () {

    val map = HashMap<Int, Int>();

    // compilation error because map[4] can be null
    //val nonExistKey:Int = map[4]

    val nonExistingKey:Int = map[4]?:-1

    print(nonExistingKey) // -1

    // if arr'y size is null, then set it to 4
    val arr = Item().arr?.size ?:  4


    // multiple chaining
    val myCountry = Item().arr?.get(0)?.country ?: "I have no country"


}

class NullableConstructor(name : String?) {
    val name = name ?: "No name provided"
}


class Item() {
    private val myAddress = Address();
    val arr = arrayListOf(myAddress)


    class Address() {
        val country = "Canada"
    }
}


class ElvisPractice {

}