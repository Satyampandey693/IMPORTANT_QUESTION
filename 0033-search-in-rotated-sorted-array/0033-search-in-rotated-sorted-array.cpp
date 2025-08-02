class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int n=nums.size();
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target) return mid;
          if(nums[mid]>=nums[0]){
            if(nums[mid]<target){
                s=mid+1;
            }
            else if(nums[0]>target){
                s=mid+1;
            }
            else e=mid-1;
          }
          else{
            if(nums[mid]>target){
                e=mid-1;
            }
            else if(target<=nums[n-1]){
                 s=mid+1;
            }
            else e=mid-1;
          }
          mid=s+(e-s)/2;
        }
        return -1;
    }
};