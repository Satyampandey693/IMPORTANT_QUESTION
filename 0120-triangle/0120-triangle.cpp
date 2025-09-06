class Solution {
public:
int find(int i,int j,vector<vector<int>>& triangle,  vector<vector<int>> &dp){
   
    if(i>=triangle.size()){
        return 0;
    }
     if(j>=triangle[i].size()) return 1e9;
     if(dp[i][j]!=-1e8) return dp[i][j];
    int p=triangle[i][j]+find(i+1,j,triangle,dp);
    int q=triangle[i][j]+find(i+1,j+1,triangle,dp);
    return dp[i][j]=min(p,q);

}
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-1e8));
        return find(0,0,triangle,dp);
    }
};