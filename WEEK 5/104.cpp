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
    int dfs(TreeNode* u) {
        if (!u) return 0;
        return 1 + max(dfs(u->left), dfs(u->right));
    }
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};
