class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = 0; i < s.size(); ++i) {
            if (dp[i]) {
                for (auto& word : wordDict) {
                    int m = word.size();
                    if (s.substr(i, m) == word) {
                        dp[i + m] = true;
                    }
                }
            }
        }
        return dp[n];
    }
};
