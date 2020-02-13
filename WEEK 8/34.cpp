class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return vector<int>({-1, -1});
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (l == nums.size() || nums[l] != target) return vector<int>({-1, -1});
        return vector<int>({l, r - 1});
    }
};
