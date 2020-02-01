class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, t = 0, start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            t += gas[i] - cost[i];
            if (t < 0) {
                start = (i + 1) % gas.size();
                t = 0;
            }
        }
        return sum >= 0 ? start : -1;
    }
};
