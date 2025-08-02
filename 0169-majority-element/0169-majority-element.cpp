class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mj=nums[0];
        int c=1;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==mj)c++;
           else{
            c--;
           }
           if(c==0) {
            mj=nums[i];
            c=1;
           }
        }
        c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==mj) c++;
        }
        if(c>nums.size()/2) return mj;
        else return -1;
    }
};