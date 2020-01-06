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
    void dfs(TreeNode* u) {
        if (!u) return;
        dfs(u->left);
        dfs(u->right);
        swap(u->left, u->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};
