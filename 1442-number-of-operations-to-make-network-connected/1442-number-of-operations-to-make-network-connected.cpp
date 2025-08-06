class Solution {
public:
  class Dsu{
      public:
      vector<int> par;vector<int> sz;vector<int> rank;
      Dsu(int n){
          par.assign(n+1,0);
          for(int i=0;i<n;i++) par[i]=i;
          rank.assign(n+1,1);
          sz.assign(n+1,1);
      }
      int findPar(int n){
          if(par[n]==n)
          return n;
          
          return par[n]=findPar(par[n]);
      }
      
    //   void Union(int u,int v){
    //       int up_u=findPar(u);
    //       int up_v=findPar(v);
    //       if(rank[up_u]==rank[up_v]){
    //           par[up_u]=up_v;
    //           rank[up_v]++;
    //       }
    //       else if(rank[up_u]>rank[up_v]){
    //           par[up_v]=up_u;
    //       }
    //       else{
    //           par[up_u]=up_v;
    //       }
    //   }
       void Union(int u,int v){
          int up_u=findPar(u);
          int up_v=findPar(v);
          if(sz[up_u]==sz[up_v]){
              par[up_u]=up_v;
              sz[up_v]+=sz[up_u];
          }
          else if(sz[up_u]>sz[up_v]){
              par[up_v]=up_u;
              sz[up_v]+=sz[up_u];
          }
          else{
              par[up_u]=up_v;
               sz[up_u]+=sz[up_v];
          }
      }
  };
    int makeConnected(int n, vector<vector<int>>& edges) {
      
Dsu* ds=new Dsu(n);
int ex=0;
for(int i=0;i<edges.size();i++){
    int up_u=ds->findPar(edges[i][0]);
    int up_v=ds->findPar(edges[i][1]);
    // int w=edges[i][2];
    if(up_u!=up_v){
        ds->Union(edges[i][0],edges[i][1]);
        // ans+=w;
    }
    else{
     ex++;
    }
}  
int c=0;
for(int i=0;i<ds->par.size();i++){
    if(ds->par[i]==i) c++;
}
if(c-1>ex) return -1;
return c-1;
    }
};