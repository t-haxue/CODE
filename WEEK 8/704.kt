class Solution {
    fun search(nums: IntArray, target: Int): Int {
        var l = 0
        var r = nums.size - 1
        var ans = -1
        while (l <= r) {
            val mid = (l + r) / 2
            if (nums[mid] == target) {
                ans = mid
                break
            } else if (nums[mid] < target) {
                l = mid + 1
            } else {
                r = mid - 1
            }
        }
        return ans
    }
}
