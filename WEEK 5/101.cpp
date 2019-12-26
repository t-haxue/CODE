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
    vector<vector<long long>> vals;
    void dfs(TreeNode* u, int depth) {
        if (vals.size() <= depth) vals.push_back(vector<long long>());
        if (u) {
            vals[depth].push_back(u->val);
            dfs(u->left, depth + 1);
            dfs(u->right, depth + 1);
        } else {
            vals[depth].push_back(2148473647);
        }
    }
    bool isSymmetric(TreeNode* root) {
        dfs(root, 0);
        for (auto& d : vals) {
            int n = d.size();
            for (int i = 0; i < n; ++i)
                if (d[i] != d[n - i - 1])
                    return false;
        }
        return true;
    }
};
