class Solution {
public:
#define ll long long 
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
       long long  q=abs(1ll*n);
        double p=(log(q))/(log(4));
       long long  r=round(p);
       cout<<q<<" "<<p<<" "<<r;
    bool t=true;
    if(n<0){
        if(r&1) t=false;
        else t=true;
    }
        return (fabs(p - r) <= 1e-10)&&t;
    }
};