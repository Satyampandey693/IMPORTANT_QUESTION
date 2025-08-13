class Solution {
public:
int find(int i,vector<int> &prices,int buy,vector<vector<vector<int>>> &dp,int tr){
    if(tr==0) return 0;
    if(i==prices.size()) return 0;
    if(dp[i][buy][tr]!=-1) return dp[i][buy][tr];
    int profit=INT_MIN;
    //buy
    if(buy){
      profit=max(-prices[i]+find(i+1,prices,0,dp,tr),find(i+1,prices,buy,dp,tr));

    }
    else{
        profit=max(prices[i]+find(i+1,prices,1,dp,tr-1),find(i+1,prices,buy,dp,tr));
    }
    return dp[i][buy][tr]=profit;
}
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return find(0,prices,1,dp,2);
    }
};