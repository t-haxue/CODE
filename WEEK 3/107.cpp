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
    static void dfs(TreeNode* u, int depth, vector<vector<int>>& ans) {
        if (!u) return;
        if (ans.size() <= depth) ans.push_back(vector<int>());
        ans[depth].push_back(u->val);
        dfs(u->left, depth + 1, ans);
        dfs(u->right, depth + 1, ans);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
