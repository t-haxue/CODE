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
    static bool dfs(TreeNode* u, int sum, int target) {
        if (!u) return false;
        sum += u->val;
        if (!(u->left) && !(u->right)) {
            if (sum == target)
                return true;
            else
                return false;
        }
        return dfs(u->left, sum, target) || dfs(u->right, sum, target);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, 0, sum);
    }
};
