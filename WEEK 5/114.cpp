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
    TreeNode* dfs(TreeNode* u) {
        if (!u) return nullptr;
        TreeNode* lt = dfs(u->left);
        TreeNode* rt = dfs(u->right);
        if (lt && rt) {
            lt->right = u->right;
            u->right = u->left;
            u->left = nullptr;
            return rt;
        } else if (lt) {
            u->right = u->left;
            u->left = nullptr;
            return lt;
        } else if (rt) {
            return rt;
        } else {
            return u;
        }
    }
    void flatten(TreeNode* root) {
        dfs(root);
    }
};
