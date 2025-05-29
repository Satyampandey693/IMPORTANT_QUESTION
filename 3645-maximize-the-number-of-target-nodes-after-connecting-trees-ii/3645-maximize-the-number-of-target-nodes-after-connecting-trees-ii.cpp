class Solution {
public:

void nodeAtevenAtodd(int n,vector<int> gr[],int par,vector<vector<int>> &dp,vector<int> &parent){
    // if(gr[n].size()==1) {
    //     dp[n][0]=1;
    //     return ;
    // }
    for(int i:gr[n]){
        if(i==par) continue;
        parent[i]=n;
        nodeAtevenAtodd(i,gr,n,dp,parent);
    }

      for(int i:gr[n]){
         if(i==par) continue;
       dp[n][0]+=dp[i][1];
       dp[n][1]+=dp[i][0];
    }
    dp[n][0]++;
    return;

}

void find(int n,vector<int> gr[],int par,vector<vector<int>> &dp){
     for(int i:gr[n]){
        if(i==par) continue;
         if(par!=-1){
            int p=dp[n][1];
               dp[n][1]+=(dp[par][0]-dp[n][1]);
               dp[n][0]+=(dp[par][1]-dp[n][0]);
                
             }
        find(i,gr,n,dp);
    }

    //   for(int i:gr[n]){
    //      if(i==par) continue;
    //    dp[n][0]+=dp[i][1];
    //    dp[n][1]+=dp[i][0];
       
    // }
    return;
}
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
         
         int n=edges1.size();
         int m=edges2.size();
         vector<int> gr[n+1];
         vector<int> gr2[m+1];
         for(int i=0;i<n;i++){
            int u=edges1[i][0];
            int v=edges1[i][1];
            gr[u].push_back(v);
            gr[v].push_back(u);

         }
         for(int i=0;i<m;i++){
            int u=edges2[i][0];
            int v=edges2[i][1];
            gr2[u].push_back(v);
            gr2[v].push_back(u);

         }

         vector<vector<int>> dp2(m+1,vector<int>(2,0));
         vector<vector<int>> dp(n+1,vector<int>(2,0));
         vector<int> parent(m+1,-1);
         nodeAtevenAtodd(0,gr2,-1,dp2,parent);
      
        // if(7<=m)
        // cout<<dp2[0][0]<<" "<<dp2[0][1];
         int maxi=0;
         find(0,gr2,-1,dp2);
       
         for(int i=0;i<m+1;i++){
             int p=0;
            p=dp2[i][1];
             maxi=max(maxi,p); 
         }
         parent.resize(n+1,-1);
          nodeAtevenAtodd(0,gr,-1,dp,parent);
          find(0,gr,-1,dp);
          vector<int> ans;
          for(int i=0;i<n+1;i++){
            int p=0;
            
            p=dp[i][0];
           
             if(parent[i]!=-1){
                int par=parent[i];
                int r=dp[par][1]-p;
               p+=r;
             }
            //  maxi=max(maxi,p);
            ans.push_back(maxi+p); 
         }
         return ans;


    }
};