class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;
        int i=0,j=0;
        long long p=0;
        int n=nums.size();
        while(i<n){
           p+=nums[i];
           int l=i-j+1;
           while(j<=i&&p*l>=k){
            p-=nums[j];
            j++;
            l=i-j+1;
           }
           if(p*l<k){
            // cout<<i<<" "<<j<<endl;
           ans+=(i-j+1);}
           i++;
        }
        return ans;
    }
};