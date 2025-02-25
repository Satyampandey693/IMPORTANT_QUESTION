class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        map<int ,int> mp;
        long long sum=0;
        
        int ans=0;
        int mod=1e9+7;
        for(int i =0;i<arr.size();i++){
            sum+=arr[i];
         int p=sum&1;
         ans=(1ll*ans+1ll*mp[!p])%mod;
         if(p){
            ans=(1ll*ans+1ll*1)%mod;
         }
        //  cout<<sum<<" "<<i<<endl;
         mp[p]++;
        }
        return ans;
    }
};