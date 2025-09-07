class Solution {
public:
   bool detect(int node,vector<int> &vis,int V, vector<vector<int>>& adj,vector<int> &path,int start){
        
        vis[node]=1;
        
       
            for(auto  i:adj[node]){
                if(vis[i]==0){
                    path[i]=start;
                    if(detect(i,vis,V,adj,path,start)) return true;
                    
                }
                else{
                    // cout<<node<<" "<<i<<" "<<path[i]<<" "<<path[node]<<endl;
                    if(path[i]!=-1) return true;;
                    // if(path[i]==path[node]) return true;
                }
            
        }
        path[node]=-1;
        return false;
}
        
     vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        int V=graph.size();
         vector<int> vis(V,0);
         vector<int> path(V,-1);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                // cout<<"i";
                path[i]=i;
                if(!detect(i,vis,V,graph,path,i))
                path[i]=-1;
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(path[i]==-1) ans.push_back(i);
        }
        return ans;
      
    }
  
};