class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        using PII = pair<int, int>;
        vector<PII> v;
        int n = ratings.size();
        for (int i = 0; i < n; ++i) {
            v.push_back(make_pair(ratings[i], i));
        }
        sort(v.begin(), v.end(), [] (PII& a, PII& b) -> bool { return a.first < b.first; });
        vector<int> a(n);
        for (int c, p, i = 0; i < n; ++i) {
            c = 1;
            p = v[i].second;
            if (p > 0 && v[i].first > ratings[p - 1]) {
                c = max(c, a[p - 1] + 1);
            }
            if (p + 1 < n && v[i].first > ratings[p + 1]) {
                c = max(c, a[p + 1] + 1);
            }
            a[p] = c;
        }
        int ans = 0;
        for (auto x : a) ans += x;
        return ans;
    }
};
