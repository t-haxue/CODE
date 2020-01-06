class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> mx;
        int n = prices.size();
        for (int price : prices) mx.push_back(price);
        for (int i = n - 2; i >= 0; --i) mx[i] = max(mx[i], mx[i + 1]);
        int ans = 0;
        for (int i = 1; i < n; ++i)
            ans = max(ans, mx[i] - prices[i - 1]);
        return ans;
    }
};
