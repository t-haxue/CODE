class Solution {
public:
    bool isPerfectSquare(int num) {
        double a = 10;
        int t = 20;
        while (t--) {
            a = (a * a + num) / (2 * a);
        }
        long long b = (long long)round(a);
        return b * b == (long long)num;
    }
};
