class Solution {
public:
bool find(string &s,string &p,int i ,int j,vector<vector<int>> &dp){
    if(i==s.size()&&j==p.size()) return true;
    if(i==s.size()) {
        for( ;j<p.size();j++){
            if(p[j]!='*') return false;
        }
        return true;
    }
    if(j==p.size()) return false;
if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==p[j]){
        return dp[i][j]=find(s,p,i+1,j+1,dp);
    }
    else {
        if(p[j]=='*'){
            return dp[i][j]=find(s,p,i+1,j,dp)|find(s,p,i,j+1,dp);
        }
        else if(p[j]=='?') return dp[i][j]=find(s,p,i+1,j+1,dp);
        else return dp[i][j]=false;
    }
return false;
}
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
        return find(s,p,0,0,dp);
    }
};