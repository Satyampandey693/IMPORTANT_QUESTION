// class Solution {
// public:
//     int minimumObstacles(vector<vector<int>>& grid) {
        
//     }
// };
class Solution {
public:
    struct compare {
    bool operator()(const pair<int,pair<int,int>>& p1, const pair<int,pair<int,int>>& p2) {
        return p1.first > p2.first; // Compare based on the first element of the pair
    }
};
    int  minimumObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,compare> pq;
        pq.push({0,{0,0}});
       int n=grid.size();
       int m=grid[0].size();
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        vector<int> r={0,-1,0,+1};
        vector<int>  c={-1,0,+1,0};
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0]=1;
        dis[0][0]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int ni=pq.top().second.first;
            int nj=pq.top().second.second;
            vis[ni][nj]=1;
            // cout<<ni<<nj<<endl;
            pq.pop();
            for(int i=0;i<4;i++){
                int nr=ni+r[i];
                int nc=nj+c[i];
                if(nr>=0&&nc>=0&&nr<n&&nc<m){
                    // dis[nr][nc]=d+1;
                    if(grid[nr][nc]==0&&dis[nr][nc]>d){
                    dis[nr][nc]=d;
                    pq.push({d,{nr,nc}});
                    vis[nr][nc]=1;
                    }
                    else if(grid[nr][nc]==1&&dis[nr][nc]>d+1){ 
                        dis[nr][nc]=d+1;
                        pq.push({d+1,{nr,nc}});}
                }

            }
           
           
        }
        if(dis[n-1][m-1]==1e9) return -1;
        return dis[n-1][m-1];
    }
};