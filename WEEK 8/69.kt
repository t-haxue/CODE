class Solution {
    fun mySqrt(x: Int): Int {
        var a = 10.0
        var t = 20
        while (t-- > 0) {
            a = (a * a + x) / (2 * a)
        }
        return a.toInt()
    }
}
