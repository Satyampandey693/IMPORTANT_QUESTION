class Solution {
public:
    int maxSum(vector<int>& nums) {
        // map<
        vector<int> arr(100+1,0);
        int mxneg=-1000;
        for(int i=0;i<nums.size();i++){
            // mini=min(mini,nums[i]);
            if(nums[i]<0) {
                mxneg=max(mxneg,nums[i]);
                continue;
            }
            arr[nums[i]]++;
            
        }
        int ans=0;
        for(int i=0;i<101;i++){
            if(arr[i]>0) ans+=i;
        }
        if(ans==0&&arr[0]==0) return mxneg;
        return ans;
    }
};