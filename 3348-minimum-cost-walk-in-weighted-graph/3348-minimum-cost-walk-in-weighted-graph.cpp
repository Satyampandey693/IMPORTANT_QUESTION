class Solution {
public:
  class DisjointSet {
    
public:
vector<int> rank, parent,tand;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        tand.resize(n+1,INT_MAX);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v,int w) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) {
            tand[ulp_v]&=w;
            return;
        }
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
            tand[ulp_v]=( tand[ulp_v]&tand[ulp_u]&w);
            
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
             tand[ulp_u]=( tand[ulp_v]&tand[ulp_u]&w);
        }
        else {
            parent[ulp_v] = ulp_u;
             tand[ulp_u]=( tand[ulp_v]&tand[ulp_u]&w);
            rank[ulp_u]++;
        }
    }
};
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
         DisjointSet *ds=new DisjointSet(n);
         for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            ds->unionByRank(u,v,w);

         }
         vector<int> ans;
         for(int i=0;i<query.size();i++){
             int u=query[i][0];
            int v = query[i][1];
            int ulp_u = ds->findUPar(u);
        int ulp_v = ds->findUPar(v);
        int r=ds->tand[ulp_u];
        if(ulp_v!=ulp_u){
            ans.push_back(-1);
        }
        else ans.push_back(r);
         }
         return ans;


    }
};