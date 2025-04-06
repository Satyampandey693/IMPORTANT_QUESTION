class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
       
        vector<int> dp(n,1);
        vector<int> has(n);
        for(int i=0;i<n;i++) has[i]=i;
        int maxInd=0;
        int maxi=0;

        for(int i=0;i<nums.size();i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0){
                   if(dp[i]<dp[prev]+1){
                    dp[i]=dp[prev]+1;
                    has[i]=prev;
                   }
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                maxInd=i;
            }
        }
       vector<int> ans;
       
       while(has[maxInd]!=maxInd){
        ans.push_back(nums[maxInd]);
        maxInd=has[maxInd];
       }
       ans.push_back(nums[maxInd]);
       reverse(ans.begin(),ans.end());
        return ans;
    }
};