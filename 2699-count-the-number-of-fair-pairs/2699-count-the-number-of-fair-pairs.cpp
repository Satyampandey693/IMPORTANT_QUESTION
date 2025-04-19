class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        // for(int i=nums.size()-1;i>=0;i--){
        //     int r=nums[i];
        //      nums.pop_back();
        //     // if(i<nums.size()-1)if(nums[i]==nums[i+1]){
        //     //     nums.pop_back();
        //     //     continue;}
        //     int p=lower-r;
        //     int mi=lower_bound(nums.begin(),nums.end(),p)-nums.begin();//min index
        //     int q=upper-r;
        //     int li=upper_bound(nums.begin(),nums.end(),q)-nums.begin();//larger index
        //     cout<<mi<<" "<<li<<endl;
        //     ans+=(li-mi);
           

        // }

        int i=0;
        int j=0;
        int k=nums.size()-1;
        while(k>i){
            

            while(j<k&&nums[j]+nums[k]<=upper){
                j++;
            }
            while(i<k&&nums[i]+nums[k]<lower){
                i++;
            }
            if(j>=k)j=k;
            // cout<<i<<" "<<j<<endl;


            ans+=(j-i);
            k--;
        }
        return ans;
    }
};