class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int np=0,nn=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)np++;
            else if(nums[i]<0)nn++;

        }
        return max(nn,np);
    }
};