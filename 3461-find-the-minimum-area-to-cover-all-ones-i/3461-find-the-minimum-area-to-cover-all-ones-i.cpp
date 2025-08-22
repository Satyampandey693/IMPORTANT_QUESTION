class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int li=m-1,ri=0,ui=n-1,bi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                li=min(li,j);
                ri=max(ri,j);
                ui=min(ui,i);
                bi=max(bi,i);
            }
        }
        return (ri-li+1)*(bi-ui+1);
    }
};