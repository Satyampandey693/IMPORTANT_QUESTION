class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        
        int n=grid.size();
        int m=grid[0].size();
        int k=queries.size();
        vector<int> delr={0,-1,0,1};
        vector<int> delc={-1,0,1,0};
        vector<vector<int>> arr;
       for(int i=0;i<k;i++){
        arr.push_back({queries[i],i});
       }
       sort(arr.begin(),arr.end());
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0]=1;
       vector<int> point(k);
       int p=0;
       for(int i=0;i<k;i++){
        int thre=arr[i][0];
        int ind =arr[i][1];
         int t=0;
       while(!pq.empty()&&pq.top().first<thre){
       
       int oi=pq.top().second.first;
       int oj=pq.top().second.second;
      
       pq.pop();
       t++;
          for(int k=0;k<4;k++){
                int ni=oi+delr[k];
                int nj=oj+delc[k];
                if(ni>=0&&nj>=0&&ni<n&&nj<m&&!vis[ni][nj]){
                   pq.push({grid[ni][nj],{ni,nj}});
                   vis[ni][nj]=1;
                }
          }
       }
            
          
        p+=t;
        point[ind]=p;
       
       }
       return point;
    }
};