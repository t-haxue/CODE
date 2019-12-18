class Solution {
public:
    string s;
    vector<string> ans;
    void dfs(int left, int right) {
        if (!left && !right) {
            ans.push_back(s);
            return;
        }
        if (left) {
            s.push_back('(');
            dfs(left - 1, right);
            s.pop_back();
        }
        if (right > left) {
            s.push_back(')');
            dfs(left, right - 1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        if (!n) return ans;
        dfs(n, n);
        return ans;
    }
};
