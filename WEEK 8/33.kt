class Solution {
    fun search(nums: IntArray, target: Int): Int {
        val hmp = HashMap<Int, Int>()
        for (i in nums.indices) {
            hmp[nums[i]] = i
        }
        return if (hmp[target] != null) hmp[target]!! else -1
    }
}
