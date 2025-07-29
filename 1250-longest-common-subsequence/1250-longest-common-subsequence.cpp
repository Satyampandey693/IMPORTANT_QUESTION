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
        // vector<vector<int>> dp( text1.size(),vector<int>( text2.size(),0));
        vector<int> prev(text2.size(),0);
        // return find(text1,text2,0,0,dp);
        for(int i=0;i<text1.size();i++){
            vector<int>  dp(text2.size(),0);
            for(int j=0;j<text2.size();j++){
                if(text1[i]==text2[j]) {dp[j]=1;
                if(i>0&&j>0){
                   dp[j]=1+prev[j-1];
                }

                }
                else{
                    if(i>0) dp[j]=prev[j];
                    if(j>0) dp[j]=max(dp[j-1],dp[j]);
                    // dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

                }
            }
            prev=dp;
        }
        return prev[text2.size()-1];


    }
};