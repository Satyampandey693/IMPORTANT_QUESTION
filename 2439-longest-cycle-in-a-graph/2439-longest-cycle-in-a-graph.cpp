class Solution {
public:
int mx=-1;
void dfs(int n,vector<int> gr[],vector<int> &vis,vector<int> &pathvis,int c){
      vis[n]=1;
      pathvis[n]=c;
      for(auto i:gr[n]){
          if(!vis[i]){
             dfs(i,gr,vis,pathvis,c+1);
            
          }
          else if(pathvis[i]){
             mx=max(mx,c+1-pathvis[i]);
              
          }
      }
      pathvis[n]=0;
  }
    int longestCycle(vector<int>& edges) {
        int V=edges.size();
         vector<int> gr[V+1];

        for(int i=0;i<edges.size();i++){
            if(edges[i]==-1) continue;
            int u=i;
            int v=edges[i];
            gr[u].push_back(v);
        }
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        // int  p=false;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                int st=1;
               dfs(i,gr,vis,pathvis,st);
            }
        }
        return mx;
    }
};