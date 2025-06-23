class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        //very good q 
        vector<int> dp(2*limit+2,0);
        int n=nums.size();
        for(int i=0;i<nums.size()/2;i++){
           int l=nums[i];
           int r=nums[n-i-1];
           int  mn=min(l,r);
           int mx=max(l,r);
           dp[2]+=2;
           dp[mn+1]--;
           dp[l+r]--;
           dp[l+r+1]++;
           dp[mx+limit+1]++;
        }
        int ans=INT_MAX;
        for(int i=2;i<2*limit+1;i++){
            dp[i]+=dp[i-1];
            ans=min(ans,dp[i]);
        }
        // cout<<dp[0]<<" "<<dp[1];
        return ans;
    }
};