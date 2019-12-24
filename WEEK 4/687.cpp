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
    int ans = 0;
    int dfs(TreeNode* u) {
        if (!u) return 0;
        int x = 1, c = 1, l = 0, r = 0;
        if (u->left) {
            l = dfs(u->left);
            if (u->val == u->left->val) {
                c += l;
                x = max(x, 1 + l);
            }

        }
        if (u->right) {
            r = dfs(u->right);
            if (u->val == u->right->val) {
                c += r;
                x = max(x, 1 + r);
            }
        }
        ans = max(ans, c);
        return x;
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return max(0, ans - 1);
    }
};
