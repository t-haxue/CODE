class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num : nums) ++cnt[num];
        unordered_map<int, int>::iterator i, j;
        int x, y, z;
        set<vector<int>> ans;
        for (i = cnt.begin(); i != cnt.end(); ++i) {
            i->second -= 1;
            for (j = i; j != cnt.end(); ++j) {
                j->second -= 1;
                x = i->first;
                y = j->first;
                z = 0 - x - y;
                if ((j->second) >= 0 && cnt.find(z) != cnt.end() && cnt[z] > 0) {
                    if (x < y) swap(x, y);
                    if (x < z) swap(x, z);
                    if (y < z) swap(y, z);
                    ans.insert(vector<int>({x, y, z}));
                }
                j->second += 1;
            }
            i->second += 1;
        }
        vector<vector<int>> ret;
        for (auto v : ans) ret.push_back(v);
        return ret;
    }
};
