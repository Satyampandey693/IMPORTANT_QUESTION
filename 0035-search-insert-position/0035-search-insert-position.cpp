class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        int ans=nums.size();
        while(s<=e){
           if(nums[mid]==target) return mid;
           if(nums[mid]>target){
            e=mid-1;
            ans=mid;
           } 
           else{
           s=mid+1;
           } 
           mid=s+(e-s)/2;
        }
        return ans;
    }
};