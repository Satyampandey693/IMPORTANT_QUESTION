
#define ll long long
 class Solution {
public:
ll pnc(ll p,ll q){
    if(p<q) return 0;
    ll ans=1;
   for(int i=q;i>0;i--){
            ans=ans*p;
            p--;
   }
   while(q>0){
    ans/=q;
    q--;
   }
   return ans;
}
    long long countGood(vector<int>& nums, int k) {
        long  long ans=0;
        int i=0;
        int j=0;
        int n=nums.size();
        map<int,int> mp;
        int r=0;
        while(i<n){
            // int t=mp[nums[i]];
         r+= mp[nums[i]]++;
        //    r+=(int)pnc(mp[nums[i]],2)-(int)pnc(t,2);
           while(r>=k&&j<i){
            // int l=mp[nums[j]];
            // mp[nums[j]]--;
            //  r+=(int)pnc(mp[nums[j]],2)-(int)pnc(l,2);
            r-=--mp[nums[j]];
             ans+=(n-i);
            //  cout<<i<<" ";
             j++;

           }
           i++;
           
        }
        return ans;

    }
};