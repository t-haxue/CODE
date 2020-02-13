import kotlin.math.*

class Solution {
    fun myPow(x: Double, n: Int): Double {
        var t = 1.0
        var y = x
        var b = n.toLong()
        val neg = b < 0
        b = abs(b)
        while (b > 0) {
            if (b and 1L == 1L) {
                t *= y
            }
            y *= y
            b = b shr 1
        }
        if (neg) {
            t = 1.0 / t
        }
        return t
    }
}
