class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
    //    vector<int> mp(2,0);
    int z=0;
    int o=0;
        long long sum=0;
        
        int ans=0;
        int mod=1e9+7;
        for(int i =0;i<arr.size();i++){
            sum+=arr[i];
         int p=sum&1;
         if(p==1){
         ans=(1ll*ans+1ll*z)%mod;
         }
         else{
            ans=(1ll*ans+1ll*o)%mod;
         }
         
         if(p){
            ans=(1ll*ans+1ll*1)%mod;
         }
        //  cout<<sum<<" "<<i<<endl;
        if(p==0) z++;
        else o++;
        }
        return ans;
    }
};