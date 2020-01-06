class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums);
        int n = 1;
        for (int i = 2; i <= nums.size(); ++i) n *= i;
        for (int i = 1; i < n; ++i) {
            next_permutation(nums.begin(), nums.end());
            ans.push_back(nums);
        }
        return ans;
    }
};
