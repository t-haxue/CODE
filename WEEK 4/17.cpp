class Solution {
public:
    vector<vector<char>> pad;
    int n;
    string s, t;
    vector<string> ans;
    void dfs(int x) {
        if (x == n) {
            ans.push_back(t);
            return;
        }
        int num = s[x] - '0';
        if (num == 1) dfs(x + 1);
        for (auto ch : pad[num]) {
            t.push_back(ch);
            dfs(x + 1);
            t.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;
        s = digits;
        n = digits.size();
        pad.push_back(vector<char>());
        pad.push_back(vector<char>());
        pad.push_back(vector<char>({'a', 'b', 'c'}));
        pad.push_back(vector<char>({'d', 'e', 'f'}));
        pad.push_back(vector<char>({'g', 'h', 'i'}));
        pad.push_back(vector<char>({'j', 'k', 'l'}));
        pad.push_back(vector<char>({'m', 'n', 'o'}));
        pad.push_back(vector<char>({'p', 'q', 'r', 's'}));
        pad.push_back(vector<char>({'t', 'u', 'v'}));
        pad.push_back(vector<char>({'w', 'x', 'y', 'z'}));
        dfs(0);
        return ans;
    }
};
