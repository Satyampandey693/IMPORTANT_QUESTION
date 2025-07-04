class Solution {
public:
#define ll long long
ll pow(ll n,  ll p) {
    if (p == 0) return 1;
    ll ans = 1;
    while (p) {
        if (p & 1) {
            ans = ans * n;
            p--;
        } else {
            n = n * n;
            p = p / 2;
        }
    }
    return ans;
}
long long ceilLog2(long long k) {
    if (k <= 1) return 0; // ceil(log2(1)) = 0
    long long ans = 0;
    k--;
    while (k > 0) {
        ans++;
        k >>= 1;
    }
    return ans;
}

    char kthCharacter(long long k, vector<int>& operations) {
         ll n=ceilLog2(k);
        n--;
        ll p=n;
        cout<<n<<endl;
        ll r=k;
        int t=0;
        while(r>1){
            // cout<<p<<endl;
            if(operations[p]) t++;
            // t++;
           ll l=pow(2,p);
           r-=l;
           if(r<=1)break;
            // cout<<p<<" "<<r<<endl;
           p=ceilLog2(r);
        //    if(p!=0)
           p--;
        }
        cout<<t;
        return 'a'+t%26;
    }
};