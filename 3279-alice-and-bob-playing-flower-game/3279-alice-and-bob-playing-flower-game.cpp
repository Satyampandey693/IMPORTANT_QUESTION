class Solution {
public:
    long long flowerGame(int n, int m) {
        long long p,q,r,s;
    //    if(n&1){
        p=n/2;
        q=n-p;
    //    }
      r=m/2;
     s=m-r;
     long long ans=0;
      ans+=p*s;
      ans+=q*r;
      return ans;

    }
};