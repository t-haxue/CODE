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
    int ans;
    int dfs(TreeNode* u) {
        if (!u) return INT_MIN;
        int l = dfs(u->left);
        int r = dfs(u->right);
        int sum = u->val + max(0, l) + max(0, r);
        ans = max(ans, sum);
        return u->val + max(0, max(l, r));
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};
