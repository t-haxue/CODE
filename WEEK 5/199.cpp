/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int depth[1005];
    int n;
    void dfs(TreeNode* u, int d) {
        if (!u) return;
        n = max(n, d);
        depth[d] = u->val;
        dfs(u->left, d + 1);
        dfs(u->right, d + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        n = -1;
        dfs(root, 0);
        vector<int> ans;
        for (int i = 0; i <= n; ++i)
            ans.push_back(depth[i]);
        return ans;
    }
};
