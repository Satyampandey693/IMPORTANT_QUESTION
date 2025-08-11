class Solution {
public:
   struct compare {
    bool operator()(const pair<int,pair<int,int>>& p1, const pair<int,pair<int,int>>& p2) {
        return p1.first > p2.first; // Compare based on the first element of the pair
    }
};
    int minimumEffortPath(vector<vector<int>>& grid) {
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,compare> pq;
        pq.push({0,{0,0}});
       int n=grid.size();
       int m=grid[0].size();
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        vector<int> r={0,-1,0,1};
        vector<int>  c={-1,0,1,0};
        dis[0][0]=0;
        while(!pq.empty()){
            int ni=pq.top().first;
            int nj=pq.top().second.first;
            int d=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nr=ni+r[i];
                int nc=nj+c[i];
                
                if(nr>=0&&nc>=0&&nr<n&&nc<m&&dis[nr][nc]>max(d,abs(grid[nr][nc]-grid[ni][nj]))){
                    dis[nr][nc]=max(d,abs(grid[nr][nc]-grid[ni][nj]));
                    pq.push({nr,{nc,dis[nr][nc]}});
                }
            }
           
           
        }
        // if(dis[n-1][m-1]==1e9) return -1;
        return dis[n-1][m-1];
    }
};