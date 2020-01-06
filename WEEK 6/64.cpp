class Solution {
public:
    int dp[1005][1005];
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, 0x3F, sizeof dp);
        dp[1][0] = dp[0][1] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
        return dp[n][m];
    }
};
