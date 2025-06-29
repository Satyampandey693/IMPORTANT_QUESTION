class Solution {
public:
#define ll long long
int mod=1e9+7;
ll pow(ll n,  ll p) {
    if (p == 0) return 1;
    ll ans = 1;
    while (p) {
        if (p & 1) {
            ans = (ans * n)%mod;
            p--;
        } else {
            n = (n * n)%mod;
            p = p / 2;
        }
    }
    return ans;
}
    int numSubseq(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        int i=0,j=0;
        int n=nums.size();
        int ans=0;
        j=n-1;
        while(i<n){
            while(j>=0&&nums[i]+nums[j]>target){
                j--;
            }
            int p=j-i;
            if(p>=0){
            ans=(ans+pow(2,p))%mod;}
            else{
                if(nums[i]*2<target)ans=(ans+1)%mod;
            }
            i++;
        }
        return (int)ans;
    }
};