class Solution {
public:

int find(int i,vector<int> &prices,int buy,vector<vector<int>> &dp,int fee){
    if(i==prices.size()) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    int profit=INT_MIN;
    //buy
    if(buy){
      profit=max(-prices[i]+find(i+1,prices,0,dp,fee),find(i+1,prices,buy,dp,fee));

    }
    else{
        profit=max(prices[i]-fee+find(i+1,prices,1,dp,fee),find(i+1,prices,buy,dp,fee));
    }
    return dp[i][buy]=profit;
}
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        // return find(0,prices,1,dp,fee); 
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
               int profit=INT_MIN;
    //buy
    if(buy){
      profit=max(-prices[i]+dp[i+1][0],dp[i+1][buy]);

    }
    else{
        profit=max(prices[i]-fee+dp[i+1][1],dp[i+1][0]);
    }
     dp[i][buy]=profit;
            }
        }
        return dp[0][1];
    }
};