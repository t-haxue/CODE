class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lh(n), rh(n);
        for (int i = 0; i < n; ++i) lh[i] = height[i];
        for (int i = 0; i < n; ++i) rh[i] = height[i];
        for (int i = 1; i < n; ++i) lh[i] = max(lh[i - 1], lh[i]);
        for (int i = n - 2; i >= 0; --i) rh[i] = max(rh[i + 1], rh[i]);
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += min(lh[i], rh[i]) - height[i];
        return sum;
    }
};
