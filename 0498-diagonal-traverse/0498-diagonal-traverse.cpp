class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int c=0;
        int n=mat.size();
        int m=mat[0].size();
        vector<int> ans;
        int flip=0;
        for(int d=0;d<n+m-1;d++,flip=!flip){
           if(flip==0){
            for(int i=min(d,n-1),j=d-i;i>=0&&j<m;i--,j++){
                ans.push_back(mat[i][j]);
            }
           }
           else{
            for(int j=min(m-1,d),i=d-j;i<n&&j>=0;i++,j--){
                 ans.push_back(mat[i][j]);
            }
           }
        }
        return ans;
    }
};