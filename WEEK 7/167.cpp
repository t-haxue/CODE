class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i, j = n - 1;
        for (i = 0; i < n; ++i) {
            while (i < j && numbers[i] + numbers[j] > target) --j;
            if (i < j && numbers[i] + numbers[j] == target) break;
            if (i >= j) return vector<int>({0, 0});
        }
        return vector<int>({i + 1, j + 1});
    }
};
