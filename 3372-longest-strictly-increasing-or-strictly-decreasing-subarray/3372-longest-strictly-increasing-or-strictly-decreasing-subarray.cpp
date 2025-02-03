class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int n=nums.size();
        int i=1,j=0,k=0;;

        while(i<n){
            if(nums[i]<=nums[i-1]){
              j=i;
            }
            if(nums[i]>=nums[i-1]){
              k=i;
            }
            ans=max(ans,i-k+1);
            ans=max(ans,i-j+1);
            i++;
        }
       
        return ans;
        
    }
};