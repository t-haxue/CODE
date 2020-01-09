class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), x = 0;
        while (true) {
            if (x >= n - 1) return true;
            int nx = x, ma = -1;
            for (int i = x; i < nums.size() && i <= x + nums[x]; ++i) {
                if (i + nums[i] > ma) {
                    ma = i + nums[i];
                    nx = i;
                }
            }
            if (ma >= n - 1) return true;
            if (nx == x) break;
            x = nx;
        }
        return false;
    }
};
