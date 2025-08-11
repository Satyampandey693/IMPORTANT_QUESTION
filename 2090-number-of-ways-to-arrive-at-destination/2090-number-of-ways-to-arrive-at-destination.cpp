class Solution {
public:
#define ll long long
int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& times) {
         vector<pair<int,int>> gr[n+1];
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            gr[u].push_back({v,w});
             gr[v].push_back({u,w});
        }
        priority_queue<pair<ll,int>,vector<pair<ll ,int>>,greater<pair<ll,int>>> pq;
        pq.push({0,0});
        vector<int> ways(n+1,0);
        ways[0]=1;
        vector<ll> dis(n+1,1e15);
        dis[0]=0;
        while(!pq.empty()){
            ll d=pq.top().first;
            int nd=pq.top().second;
            pq.pop();
            for(auto i:gr[nd]){
                int nx=i.first;
                ll di=i.second;
                if(d+1ll*di<dis[nx]){
                    dis[nx]=d+1ll*di;
                     ways[nx]=ways[nd];
                    pq.push({dis[nx],nx});
                }
                else if(d+1ll*di==dis[nx]){
                    ways[nx]=(ways[nx]+1ll*ways[nd])%mod;
                }
            }
        }
        return ways[n-1];

    }
};