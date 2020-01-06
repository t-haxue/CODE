class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int n = prices.size();
        const int INF = 0x3F3F3F3F;
        int *buy = new int[n];
        int *sell = new int[n];
        int *dp = new int[n];
        sell[0] = 0;
        buy[0] = -prices[0];
        dp[0] = sell[0];
        buy[1] = max(-prices[0], -prices[1]);
        sell[1] = buy[0] + prices[1];
        dp[1] = max(dp[0], sell[1]);
        for (int i = 2; i < n; ++i) {
            sell[i] = buy[i - 1] + prices[i];
            buy[i] = max(buy[i - 1], dp[i - 2] - prices[i]);
            dp[i] = max(dp[i - 1], sell[i]);
        }
        return dp[n - 1];
    }
};
