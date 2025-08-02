class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
         int n=nums.size();
         if(n==1) return nums[0];
        if(nums[0]>nums[1]) return nums[0];
        if(nums[n-1]>nums[n-2])  return nums[n-1];
         int s=1;
        // int n=nums.size();
        int e=nums.size()-2;
        int mid=s+(e-s)/2;
        // int st=0;
        // int l=n-1;
        while(s<=e){
          if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]) return mid;
          if(nums[mid]>nums[mid+1]){
            e=mid-1;

          }
          else{
            s=mid+1;
          }
          mid=s+(e-s)/2;
        }
        return -1;
    }
};