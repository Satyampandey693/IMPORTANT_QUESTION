class Solution {
public:
    int findCheapestPrice(int V, vector<vector<int>>& edges, int src, int dst, int k) {

        // vector<pair<int,int>> gr[n];
        // for(int i=0;i<flights.size();i++){
        //     int u=flights[i][0];
        //     int v=flights[i][1];
        //     int w=flights[i][2];
        //     gr[u].push_back({v,w});
        // }
        // priority_queue<pair<int ,pair<int,int>>,vector<pair<int ,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        // pq.push({0,{0,src}});
        // vector<int> dis(n,1e9);
        // dis[src]=0;
        // while(!pq.empty()){
        //     int t=pq.top().first;
        //     int d=pq.top().second.first;
        //     int nd=pq.top().second.second;
        //     pq.pop();
        //     for(auto i:gr[nd]){
        //         int nx=i.first;
        //         int di=i.second;
        //         if(t<=k&&d+di<dis[nx]){
        //             dis[nx]=d+di;
        //             pq.push({t+1,{dis[nx],nx}});
        //         }
        //     }
        // }
        // if(dis[dst]!=1e9) return dis[dst];
        // return -1; 
 vector<int> dis(V,1e9);
//  sort(edges.begin(),edges.end());
//  reverse(edges.begin(),edges.end());
        dis[src]=0;
        for(int i=0;i<=k;i++){
            vector<int> newDis=dis;
            for(int j=0;j<edges.size();j++){
                int u=edges[j][0];
                int v=edges[j][1];
                int w=edges[j][2];
                if(dis[u]!=1e9)
               newDis[v]=min(newDis[v],dis[u]+w);
            }
            dis=newDis;
        }
        //  for(int i=0;i<edges.size();i++){
        //         int u=edges[i][0];
        //         int v=edges[i][1];
        //         int w=edges[i][2];
        //         if(dis[u]+w<dis[v]&&dis[u]!=1e8) return {-1};
        //     }
        // return dis;
       if(dis[dst]!=1e9) return dis[dst];
       return -1;

    }
};