class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int mxSum=nums[0];
        int sum=nums[0];
        int n=nums.size();
        int i=1;
        while(i<n){
            if(nums[i]<=nums[i-1]){
                mxSum=max(mxSum,sum);
                sum=0;
            }
            sum+=nums[i];
            i++;
        }
        mxSum=max(mxSum,sum);
        return mxSum;
    }
};