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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ans;
        TreeNode* p = root;
        while (p || !stk.empty()) {
            while (p) {
                ans.push_back(p->val);
                stk.push(p);
                p = p->left;
            }
            if (!stk.empty()) {
                p = stk.top();
                stk.pop();
                p = p->right;
            }
        }
        return ans;
    }
};
