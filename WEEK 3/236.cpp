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
    int pv, qv;
    TreeNode* dfs(TreeNode* u) {
        if (!u) return nullptr;
        if (u->val == pv || u->val == qv) return u;
        TreeNode* l = dfs(u->left);
        TreeNode* r = dfs(u->right);
        if (l && r) return u;
        if (l) return l;
        if (r) return r;
        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pv = p->val;
        qv = q->val;
        return dfs(root);
    }
};
