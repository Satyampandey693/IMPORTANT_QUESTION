class Solution {
public:
    int findMin(vector<int>& nums) {
         int s=0;
        int n=nums.size();
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        int ans=INT_MAX;
        while(s<=e){
            // if(nums[mid]==target) return mid;
          if(nums[mid]>=nums[s]){
            ans=min(ans,nums[s]);
            s=mid+1;
            ans=min(ans,nums[mid]);
            
          }
          else{
          e=mid-1;
          ans=min(ans,nums[mid]);
          }
          mid=s+(e-s)/2;
        }
        return ans;
    }
};