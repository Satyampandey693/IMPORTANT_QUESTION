class Solution {
public:
int mod=1e9+7;
int fpow(long long x,long long p){
    int ans=1;
    while(p){
        if(p&1){
            ans=(1ll*ans*x)%mod;
            p=p-1;
        }
        else{
            x=(x*x)%mod;
            p=p/2;
        }

    }
    return ans;
}
    int countGoodNumbers(long long n) {
        // vector<int> prime={2,3,5,7};
        // vector<int> even={}
        // if(n==1) return 5;
        // if(n&1) return 1ll*5*countGoodNumbers(n-1)%mod;
        // else return 1ll*4*countGoodNumbers(n-1)%mod;
     if(n==1) return 5;
        long long odd=ceil(n/2.0);
        long long even=n/2;
        // cout<<odd<<even;
        int ans= (1ll*fpow(5,odd)*fpow(4,even))%mod;
        return ans;

    }
};