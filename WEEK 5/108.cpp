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
    vector<int> nums;
    TreeNode* build(int l, int r) {
        int m = (l + r) >> 1;
        TreeNode* u = new TreeNode(nums[m]);
        if (l < m) u->left = build(l, m);
        if (m + 1 < r) u->right = build(m + 1, r);
        return u;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        this->nums = nums;
        return build(0, nums.size());
    }
};
