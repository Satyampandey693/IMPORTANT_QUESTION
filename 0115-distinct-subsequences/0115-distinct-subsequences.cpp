class Solution {
public:
int find(string s,string t,int i,int j,  vector<vector<int>> &dp){
    if(j==t.size()) return 1;
    if(i==s.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]){
       return  dp[i][j]=find(s,t,i+1,j,dp)+find(s,t,i+1,j+1,dp);
    }
    else {
        return dp[i][j]=find(s,t,i+1,j,dp);
    }

}
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return find(s,t,0,0,dp);
    }
};