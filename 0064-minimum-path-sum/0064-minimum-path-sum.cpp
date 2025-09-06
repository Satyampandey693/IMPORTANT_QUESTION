class Solution {
public:
int find(int i,int j,vector<vector<int>>& triangle,  vector<vector<int>> &dp){
   if(i==triangle.size()-1&&j==triangle[0].size()-1) return triangle[i][j];
    if(i>=triangle.size()){
        return 1e9;
    }
    
     if(j>=triangle[i].size()) return 1e9;
     if(dp[i][j]!=-1e8) return dp[i][j];
    int p=triangle[i][j]+find(i,j+1,triangle,dp);
    int q=triangle[i][j]+find(i+1,j,triangle,dp);
    return dp[i][j]=min(p,q);

}
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1e8));
        return find(0,0,grid,dp);
    }
};