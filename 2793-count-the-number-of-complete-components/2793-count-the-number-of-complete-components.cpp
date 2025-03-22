class Solution {
public:
  class DisjointSet {
    
public:
vector<int> rank, parent,edges,size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
       edges.resize(n+1,0);
      size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) {
           
            return;
        }
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
           
           
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
            
         
        }
        else {
            parent[ulp_v] = ulp_u;
            
            rank[ulp_u]++;
        }
    }
      void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) {
             edges[ulp_u]++;
             return;}
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
             edges[ulp_v]+=edges[ulp_u]+1;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
          edges[ulp_u]+=edges[ulp_v]+1;
            size[ulp_u] += size[ulp_v];
        }
    }
    int noOfCompleteComponents(){
        int t=0;
        for(int i=0;i<rank.size()-1;i++){
          if(parent[i]==i){
             int p=size[i];
             int r=p*(p-1)/2;
             if(r==edges[i]) t++;
          }
        }
        return t;
    }
};
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet *ds=new DisjointSet(n);
       
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
             ds->unionBySize(u,v);
        }
        return ds->noOfCompleteComponents();

      
    }
};