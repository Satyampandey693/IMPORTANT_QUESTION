class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int,int>> gr[n];
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            gr[u].push_back({v,w});
        }
        priority_queue<pair<int ,pair<int,int>>,vector<pair<int ,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,src}});
        vector<int> dis(n,1e9);
        dis[src]=0;
        while(!pq.empty()){
            int t=pq.top().first;
            int d=pq.top().second.first;
            int nd=pq.top().second.second;
            pq.pop();
            for(auto i:gr[nd]){
                int nx=i.first;
                int di=i.second;
                if(t<=k&&d+di<dis[nx]){
                    dis[nx]=d+di;
                    pq.push({t+1,{dis[nx],nx}});
                }
            }
        }
        if(dis[dst]!=1e9) return dis[dst];
        return -1; 

    }
};