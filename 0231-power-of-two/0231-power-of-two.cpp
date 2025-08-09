class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        int count=0;
        while(n!=0){
            int r=n&1;
            n=n>>1;
            if(r==1) count++;
            if(count>1) return false;
        }
        return true;
    }
};