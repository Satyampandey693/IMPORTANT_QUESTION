class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        int k=0;
        while(k<n){
            if(nums[k]!=0){
             swap(nums[i],nums[k]);
             i++;
            }
           k++;
        }
        // for(int i=0;i<nums.size();i++) cout<<nums[i]<<"";

    }
};