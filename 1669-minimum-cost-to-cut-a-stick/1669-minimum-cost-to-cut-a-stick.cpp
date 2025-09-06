class Solution {
public:
   int find(int i,int j,vector<int> &cuts, vector<vector<int>> &dp){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int mn=INT_MAX;
    for(int k=i;k<=j;k++){
        int p=(cuts[j+1]-cuts[i-1])+find(i,k-1,cuts,dp)+find(k+1,j,cuts,dp);
        mn=min(mn,p);
    }
    return dp[i][j]=mn;
   }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<int> nc;
        nc.push_back(0);
        // nc.insert(cuts.begin(),cuts.end(),nc.end());
        for(int i=0;i<cuts.size();i++) nc.push_back(cuts[i]);
        nc.push_back(n);
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
       return  find(1,nc.size()-2,nc,dp);
    }
};