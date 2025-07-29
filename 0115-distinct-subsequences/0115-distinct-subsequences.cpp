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
         vector<vector<uint64_t>> dp(s.size()+1,vector<uint64_t> (t.size()+1,0));
    for(int i = 0; i <= s.size(); i++) dp[i][0] = 1;
    for(int i = 1; i <= s.size(); i++) {
        for(int j = 1; j <= t.size(); j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return (int)dp[s.size()][t.size()];
    }
};