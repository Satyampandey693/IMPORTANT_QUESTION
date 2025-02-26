class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0;
        int ans=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans=max(ans,sum);
            if(sum<0) sum=0;
           nums[i]=nums[i]*(-1);
        }
        sum=0;
         for(int i=0;i<n;i++){
            sum+=nums[i];
            ans=max(ans,sum);
            if(sum<0) sum=0;
           nums[i]=nums[i]*(-1);
        }
        return ans;
    }
};