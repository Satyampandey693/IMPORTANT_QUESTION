class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int n=nums.size();
        int i=1,j=0;
        while(i<n){
            if(nums[i]<=nums[i-1]){
              j=i;
            }
            ans=max(ans,i-j+1);
            i++;
        }
       i=1,j=0;
        while(i<n){
            if(nums[i]>=nums[i-1]){
              j=i;
            }
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
        
    }
};