class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], m = 0;
        for (int x : nums) {
            m += x;
            ans = max(ans, m);
            if (m < 0) m = 0;
        }
        return ans;
    }
};
