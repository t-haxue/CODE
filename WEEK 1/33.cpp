class Solution {
public:
    int bs(int l, int r, vector<int>& nums, int target) {
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] == target) return m;
            if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int l = 0, r = nums.size() - 1;
        int sp = nums[0];
        int mx = 0;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] < sp)
                r = m - 1;
            else {
                mx = max(mx, m);
                l = m + 1;
            }
        }
        int a1 = bs(0, mx, nums, target);
        int a2 = bs(mx + 1, nums.size() - 1, nums, target);
        return a1 + a2 + 1;
    }
};
