class Solution {
public:
    vector<vector<int>> ans;
    vector<int> a;
    bool vis[10010];
    void dfs(int x) {
        if (x == a.size()) {
            vector<int> v;
            for (int i = 0; i < x; ++i)
                if (vis[i]) v.push_back(a[i]);
            ans.push_back(v);
            return;
        }
        vis[x] = false;
        dfs(x + 1);
        vis[x] =  true;
        dfs(x + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        a = nums;
        dfs(0);
        return ans;
    }
};
