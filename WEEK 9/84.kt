import java.util.*
import kotlin.math.max

class Solution {
    fun largestRectangleArea(heights: IntArray): Int {
        if (heights.isEmpty()) return 0
        val left = IntArray(heights.size)
        val right = IntArray(heights.size)
        left.fill(-1)
        right.fill(heights.size)
        val stk = Stack<Int>()
        for (i in heights.indices) {
            while (!stk.empty() && heights[i] < heights[stk.peek()]) {
                right[stk.pop()] = i
            }
            stk.push(i)
        }
        stk.clear()
        for (i in heights.size - 1 downTo 0) {
            while (!stk.empty() && heights[i] < heights[stk.peek()]) {
                left[stk.pop()] = i
            }
            stk.push(i)
        }
        var ans = Int.MIN_VALUE
        for (i in heights.indices) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i])
        }
        return ans
    }
}
