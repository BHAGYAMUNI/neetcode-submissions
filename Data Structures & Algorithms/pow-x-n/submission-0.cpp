class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long m = n; 
        if (m < 0) {
            m = -m; 
            x = 1.0 / x; 
        }
        while (m > 0) {
            if (m % 2 == 1) {
                ans = ans * x;
                m -= 1;
            } else {
                m = m / 2;
                x = x * x;
            }
        }
        return ans;
    }
};
