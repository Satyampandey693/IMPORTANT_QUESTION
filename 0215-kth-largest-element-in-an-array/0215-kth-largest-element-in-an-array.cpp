class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int s=-1e4;
        int e=1e4;
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            int eq=0;
            int lr=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>mid) lr++;
                else if(nums[i]==mid) eq++;

            }
            if(lr>=k||lr+eq>=k){
                ans=mid;
                s=mid+1;

            }
            else {
              e=mid-1;

            }
           mid=s+(e-s)/2; 
        }
        return ans;

    }
};