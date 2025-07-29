class Solution {
public:
int find(int i,int j,string p,string q,  vector<vector<int>> &dp){
    if(i==p.size()&&j==q.size()) return 0;
    if(j==q.size()) return p.size()-i;
    if(i==p.size()) return q.size()-j;
    if(dp[i][j]!=-1) return dp[i][j];
    
    //match
     int s;
    if(p[i]==q[j]){
     return dp[i][j]=s = find(i+1,j+1,p,q,dp);
    }
    
    //not match
    int t=1+find(i,j+1,p,q,dp);
    int l=1+find(i+1,j,p,q,dp);
    int f=1+find(i+1,j+1,p,q,dp);
    return dp[i][j]=min(t,min(l,f));

}
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return find(0,0,word1,word2,dp);

    }
};