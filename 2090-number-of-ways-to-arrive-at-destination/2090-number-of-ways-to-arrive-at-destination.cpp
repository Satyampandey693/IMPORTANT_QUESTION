class Solution {
public:
 struct compare {
    bool operator()(const pair<long long ,int>& p1, const pair<long long ,int>& p2) {
        return p1.first > p2.first; // Compare based on the first element of the pair
    }
};
    int countPaths(int n, vector<vector<int>>& flights) {
        // cout<<n;
        int V=n;
        vector<pair<int,int>> adj[V];
        int mod=1e9+7;
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int d=flights[i][2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        priority_queue<pair<long long ,int>,vector<pair<long long ,int>>,compare> pq;
        pq.push({0,0});
        vector<long long > ways(V,0);
        vector<long long > dis(V,1e12);
        ways[0]=1;
        dis[0]=0;
        while(!pq.empty()){
           long long  d=pq.top().first;
            int n=pq.top().second;
           
            pq.pop();
           
            for(auto i:adj[n]){
                if(dis[i.first]>d+i.second){
                    ways[i.first]=ways[n];
                    dis[i.first]=d+i.second;
                    pq.push({d+i.second,i.first});
                }
                else if(dis[i.first]==d+i.second){
                         ways[i.first]=(ways[n]+ ways[i.first])%mod;
                }
            }
        }
      
    //   for(auto i:mp[n-1]){
    //     while(mp[i]){

    //     }
    //   }
    // cout<<dis[n-1];
        // if(dis[n-1]!=1e12&&ways[n-1]==0) return 1;
        return ways[n-1]%mod;

    }
};