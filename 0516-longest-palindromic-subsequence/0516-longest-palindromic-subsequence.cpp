class Solution {
public:
int find(int i,int j,string &s,  vector<vector<int>> &dp){
    if(i==j) return 1;
    else if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    //not equal 
    if(s[i]==s[j]){
        return dp[i][j]= 2+find(i+1,j-1,s,dp);
    }
    else{
        int p=find(i+1,j,s,dp);
        int q=find(i,j-1,s,dp);
        return dp[i][j]=max(p,q);
    }
}
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return find(0,n-1,s,dp);
    }
};