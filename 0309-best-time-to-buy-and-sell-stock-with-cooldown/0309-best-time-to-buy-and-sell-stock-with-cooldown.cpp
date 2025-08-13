class Solution {
public:
int find(int i,vector<int> &prices,int buy,vector<vector<int>> &dp){
    if(i>=prices.size()) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    int profit=INT_MIN;
    //buy
    if(buy){
      profit=max(-prices[i]+find(i+1,prices,0,dp),find(i+1,prices,buy,dp));

    }
    else{
        profit=max(prices[i]+find(i+2,prices,1,dp),find(i+1,prices,buy,dp));
    }
    return dp[i][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return find(0,prices,1,dp);
    }
};