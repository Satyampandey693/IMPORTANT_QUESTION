class Solution {
public:
int  dfs(int i,int j,vector<vector<int>>& matrix,int length,int &maxlength,int val,int &ml, vector<vector<int>> &dp){
    //all adjacent
// maxlength=max(maxlength,length);
// ml=max(ml,length);
if(dp[i][j]!=-1){
//     length+=dp[i][j]-1;
//     maxlength=max(maxlength,length);
//    ml=max(ml,length);
   return dp[i][j];
}
    int delr[4]={0,-1,0,1};
    int delc[4]={-1,0,1,0};
    int l=1;
    for(int p=0;p<4;p++){
        int nr=i+delr[p];
        int nc=j+delc[p];
        if(nr>=0&&nr<matrix.size()&&nc>=0&&nc<matrix[0].size()&&matrix[nr][nc]>val){
           l=max(l,1+dfs(nr,nc,matrix,length+1,maxlength,matrix[nr][nc],ml,dp));
        }
    }
   return  dp[i][j]=l;
    // cout<<matrix[i][j]<<" ";

}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         int maxlength=0;
         vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                int length=1;
               
                int ml=1;
                dp[i][j]=dfs(i,j,matrix,length,maxlength,matrix[i][j],ml,dp);
                // cout<<ml<<" ";
                ;
                maxlength=max(maxlength,dp[i][j]);
                // cout<<endl;
            }
        }
        return maxlength;
    }
};