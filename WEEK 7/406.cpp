class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [] (vector<int>& a, vector<int>& b) -> bool { return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]); });
        vector<vector<int>> q;
        for (auto& p : people) {
            q.insert(next(q.begin(), p[1]), p);
        }
        return q;
    }
};
