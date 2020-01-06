class Solution {
public:
    string longestPalindrome(string s) {
        string ms;
        for (auto& ch : s) {
            ms.push_back('#');
            ms.push_back(ch);
        }
        ms.push_back('#');
        if (ms.size() == 1) return string("");
        vector<int> radius(ms.size());
        int R = -1, c = -1;
        for (int i = 0; i < radius.size(); ++i) {
            radius[i] = R > i ? min(radius[2 * c - i], R - i + 1) : 1;
            while (i + radius[i] < ms.size() && i - radius[i] >= 0 &&
                   ms[i + radius[i]] == ms[i - radius[i]]) ++radius[i];
            if (i + radius[i] > R) {
                R = i + radius[i] - 1;
                c = i;
            }
        }
        int ma = -1, pos = -1;
        for (int i = 0; i < radius.size(); ++i) {
            if (radius[i] > ma) {
                ma = radius[i];
                pos = i;
            }
        }
        string ans;
        for (int i = pos - ma + 1; i < pos + ma; ++i)
            if (ms[i] != '#') ans.push_back(ms[i]);
        return ans;
    }
};
