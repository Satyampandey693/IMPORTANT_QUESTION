class Solution {
public:
int find(int i,int j,vector<vector<int>>& triangle,  vector<vector<int>> &dp){

   if(i==triangle.size()-1&&j==triangle[0].size()-1) {
    if(triangle[i][j]==0) return 1;
    else return 0;
   }
    if(i>=triangle.size()){
        return 0;
    }
    
     if(j>=triangle[i].size()) return 0;
    if(triangle[i][j]==1) return 0;

    
     if(dp[i][j]!=-1e8) return dp[i][j];
    int p=find(i,j+1,triangle,dp);
    int q=find(i+1,j,triangle,dp);
    return dp[i][j]=p+q;;

}
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m,vector<int>(n,0));
           vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1e8));
        return find(0,0,grid,dp);
    }
};