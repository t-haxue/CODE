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
    vector<int> pre, ino;
    TreeNode* build(int lp, int rp, int li, int ri) {
        int rtval = pre[lp];
        TreeNode* u = new TreeNode(rtval);
        int p;
        for (int i = li; i < ri; ++i)
            if (ino[i] == rtval) {
                p = i;
                break;
            }
        int ls = p - li, rs = ri - p - 1;
        if (ls) u->left = build(lp + 1, lp + ls + 1, li, p);
        if (rs) u->right = build(lp + ls + 1, rp, p + 1, ri);
        return u;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        this->pre = preorder;
        this->ino = inorder;
        return build(0, preorder.size(), 0, inorder.size());
    }
};
