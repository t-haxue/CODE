import java.util.*

class Solution {
    fun nextGreaterElements(nums: IntArray): IntArray {
        val a = IntArray(nums.size * 2)
        val nxt = IntArray(a.size)
        nums.copyInto(a)
        nums.copyInto(a, nums.size)
        nxt.fill(a.size)
        val stk = Stack<Int>()
        for (i in a.indices) {
            while (!stk.empty() && a[i] > a[stk.peek()]) {
                nxt[stk.pop()] = i
            }
            stk.push(i)
        }
        val ans = IntArray(nums.size)
        for (i in ans.indices) {
            if (nxt[i] == a.size) {
                ans[i] = -1
            }
            else {
                ans[i] = a[nxt[i]]
            }
        }
        return ans
    }
}
