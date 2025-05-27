class Solution {
public:
    int differenceOfSums(int n, int m) {
        int p=n*(n+1)/2;
        int s=0;
        int r=n/m;
        int q=r*(r+1)/2;
        q=q*m;
        return p-2*q;
    }
};