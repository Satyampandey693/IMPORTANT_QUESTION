class Solution {
public:
int find(string &s1,string &s2,int i,int j, vector<vector<int>> &dp){
    if(i>=s1.size()||j>=s2.size()) return 0;
    //matches
    int p=0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]){
   int q=1+find(s1,s2,i+1,j+1,dp);
   return dp[i][j]=q;
    }
    else{
        int q=find(s1,s2,i+1,j,dp);
        int r=find(s1,s2,i,j+1,dp);
        return dp[i][j]=max(q,r);
    }
    return p;
}
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp( text1.size(),vector<int>( text2.size(),-1));
        return find(text1,text2,0,0,dp);
    }
};