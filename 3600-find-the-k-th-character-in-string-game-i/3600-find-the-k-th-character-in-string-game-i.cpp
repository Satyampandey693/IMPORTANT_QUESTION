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
    char kthCharacter(int k) {
        int n=ceil(log2(k));
        n--;
        int p=n;
        // cout<<n<<endl;
        int r=k;
        int t=0;
        while(r>1){
            t++;
           int l=(int)pow(2,p);
           r-=l;
           if(r<=1)break;
            // cout<<p<<" "<<r<<endl;
           p=ceil(log2(r));
        //    if(p!=0)
           p--;
        }
        return 'a'+t;

    }
};