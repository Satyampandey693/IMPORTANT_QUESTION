class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int s=0;
        int n=nums.size();
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        // int st=0;
        // int l=n-1;
        while(s<=e){
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[s]&&nums[mid]==nums[e]){
            s++;
            e--;
            mid=s+(e-s)/2;
             continue;

        }
          if(nums[mid]>=nums[s]){
            if(nums[mid]<target){
                s=mid+1;
            }
            else if(nums[s]>target){
                s=mid+1;
            }
            else e=mid-1;
          }
          else{
            if(nums[mid]>target){
                e=mid-1;
            }
            else if(target<=nums[e]){
                 s=mid+1;
            }
            else e=mid-1;
          }
          mid=s+(e-s)/2;
        }
        return false;
    }
};