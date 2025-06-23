   #define  ll long long
 ll tens[] = {1,      10,      100,      1000,      10000,
                           100000, 1000000, 10000000, 100000000, 1000000000};
class Solution {
public:


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
int digit[64];
    bool isMirror(long long x, int k) {
        int len=0;
        for (; x>0 ; x/=k)
            digit[len++]=x%k;

        for (int i=0, j=len-1; i<j; i++, j--) {
            if (digit[i]!=digit[j])
                return 0;
        }
        return 1;
    }
    long long rev(long long x) {
        long long ans=0;
        for(; x>0; x/=10) 
            ans=ans*10+x%10;
        return ans;
    }

     long long kMirror(int k, int n) {
        long long sum=0;

        // Start from 1-digit palindromes and grow
        for (int len=1; ; len++) {
            int half=(len+1)/2;
            for (int i=tens[half-1]; i<tens[half]; i++) {
                long long pal=(len&1)?i*tens[half-1]+rev(i/10):i*tens[half]+rev(i);
                if (isMirror(pal, k)) {
                    sum+=pal;
                    if (--n==0) return sum;
                }
            }
        }

        return sum; 
    }
};