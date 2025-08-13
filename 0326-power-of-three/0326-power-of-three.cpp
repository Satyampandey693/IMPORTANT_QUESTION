class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1) return false;
        double p = log(n) / log(3);
        cout << p << " "; // debug
        int r = int(round(p));
        cout << r; // debug
        return fabs(p - r) <= 1e-10;
    }
};
