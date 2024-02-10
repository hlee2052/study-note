package array

fun main() {
    val arr0: ArrayList<String> = arrayListOf<String>();
    arr0.add("hello")
    arr0.add("world");
    arr0[0] = "bye"
    println(arr0.joinToString()); //"bye, world"

    // different items
    val arr1 = arrayOf(1, Cat() , "ff");

    // if item is not modified, then use val
    val arr2 = arrayOf(1, "f", 3)
    println(arr2.joinToString()) // "1, f, 3"

    // null arrays
    val arr3: Array<Int?> = arrayOfNulls(3)
    println(arr3.joinToString()) // null, null, null

    // immutable empty array
    var arr4 = emptyArray<String>()
    println(arr4.joinToString()) // ""

    // use var if reference is modified
    var arr5 = arrayOf(1, 2, 3)
    arr5 = arrayOf(4, 5, 6)

    /*
    cannot do:
    var arr5 = arrayOf(1,2,3)
    arr5 = arrayListOf(1,2,3)
     */

    // array constructor
    val arr6 = Array<Int>(3) {0}
    println(arr6.joinToString()) // 0, 0, 0

    // 2D array.
    /*
     [ [0 0 0]
       [0 0 0] ]
     */
    val arr7 = Array(2) { Array<Int>(3) {0} }
    arr7[1][2] = 7
    println(arr7[1][2])

    /*
    types:
    IntArray   int[]
    BooleanArray
    ByteArray
    CharArray
    DoubleArray
    FloatArray
    IntArray
    LongArray
    ShortArray
     */

    // this is array, similar to java, need to specify size
    var arr8   = IntArray(5);
    var arrArr = intArrayOf(1,4,4);

    // TODO: this form is most standard
    var arr9 = ArrayList<Int>();
    var arr10: ArrayList<Cat> = ArrayList();

    //var arr11 = ArrayList()  compilation error since cannot infer type.

    // Operations

    var arr11 =  ArrayList<String>()
    arr11.add("asdf");
    arr11.addAll(arrayListOf("add", "more", "stuff"))

    arr11.remove("adf")
    arr11.set(1, "new item")
    arr11.removeAt(1)

    var bool1 = "asdf" in arr11;
    var size1 = arr11.size

    var arrayForm = arr11.toArray();

    arr11.clear();
    var cloned = arr11.clone();
    var sublist = arr11.subList(0, 4)






}

class Cat {

}