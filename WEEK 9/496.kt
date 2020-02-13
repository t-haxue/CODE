import java.util.*
import kotlin.collections.HashMap

class Solution {
    fun nextGreaterElement(nums1: IntArray, nums2: IntArray): IntArray {
        val stk = Stack<Int>()
        val nxt = IntArray(nums2.size)
        val pos = HashMap<Int, Int>()
        nxt.fill(-1)
        for (i in nums2.indices) {
            while (!stk.empty() && nums2[stk.peek()] < nums2[i]) {
                nxt[stk.pop()] = nums2[i]
            }
            stk.push(i)
            pos[nums2[i]] = i
        }
        val ans = IntArray(nums1.size)
        for (i in ans.indices) {
            ans[i] = nxt[pos[nums1[i]]!!]
        }
        return ans
    }
}
