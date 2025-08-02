class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());
        int n=nums.size();
        int i=n-2;
        while(i>=0&&nums[i]>=nums[i+1]){
        i--;
        }
        if(i<0) reverse(nums.begin(),nums.end());
        else{
            // int ind=n-1;
            for(int j=n-1;j>i;j--){
               if(nums[j]>nums[i]){
                swap(nums[i],nums[j]);
                break;
               }
            }
            reverse(nums.begin()+i+1,nums.end());
        }

    }
};