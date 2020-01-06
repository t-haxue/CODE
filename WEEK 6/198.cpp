class Solution {
public:
    int dp[100005][2];
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        int n = nums.size() - 1;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        return max(dp[n][0], dp[n][1]);
    }
};
