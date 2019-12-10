class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, ans = 0;
        for (int res = height.size() - 1; res > 0; --res) {
            ans = max(ans, min(height[i], height[j]) * res);
            if (height[i] < height[j])
                ++i;
            else
                --j;
        }
        return ans;
    }
};
