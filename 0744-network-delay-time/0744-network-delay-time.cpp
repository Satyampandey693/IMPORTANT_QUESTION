class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
          vector<pair<int,int>> gr[n+1];
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            gr[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int ,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> dis(n+1,1e9);
        dis[k]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int nd=pq.top().second;
            pq.pop();
            for(auto i:gr[nd]){
                int nx=i.first;
                int di=i.second;
                if(d+di<dis[nx]){
                    dis[nx]=d+di;
                    pq.push({dis[nx],nx});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dis[i]==1e9) return -1;
            ans=max(dis[i],ans);
        }
        return ans; 
    }
};