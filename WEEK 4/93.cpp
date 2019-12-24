class Solution {
public:
    bool check(string t) {
        if (t.size() == 0 || (t[0] == '0' && t.size() > 1)) return false;
        int x;
        sscanf(t.c_str(), "%d", &x);
        return x >= 0 && x <= 255;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string dot("."), a, b, c, d, t;
        if (s.size() < 4 || s.size() > 12) return ans;
        for (int i = 0; i < s.size(); ++i)
            for (int j = i + 1; j < s.size(); ++j)
                for (int k = j + 1; k < s.size(); ++k) {
                    a = s.substr(0, i + 1);
                    b = s.substr(i + 1, j - i);
                    c = s.substr(j + 1, k - j);
                    d = s.substr(k + 1);
                    t = a + dot + b + dot + c + dot + d;
                    if (check(a) && check(b) && check(c) && check(d)) ans.push_back(t);
                }
        return ans;
    }
};
