class Solution {
public:
    int kDist(int n,vector<int> gr[],int d,int k,int par){
         if(d>k)return 0;
        
        int r=0;
        for(auto i:gr[n]){
            if(par==i) continue;
        r+=kDist(i,gr,d+1,k,n);

        }
        return r+1;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size();
        int m=edges2.size();
        vector<int> gr1[n+1];
        vector<int> gr2[m+1];
        for(int i=0;i<n;i++){
          int u=edges1[i][0];
          int v=edges1[i][1];
          gr1[u].push_back(v);
          gr1[v].push_back(u);

        }

         for(int i=0;i<m;i++){
          int u=edges2[i][0];
          int v=edges2[i][1];
          gr2[u].push_back(v);
          gr2[v].push_back(u);

        }
    //    int  kDist(0,gr1,0,k,-1);
       int mx=0;
       for(int i=0;i<=m;i++){
        int p=kDist(i,gr2,0,k-1,-1);
        mx=max(mx,p);
       }

       vector<int> ans;
       for(int i=0;i<=n;i++){
        int p=kDist(i,gr1,0,k,-1);
        // cout<<p;
        ans.push_back(mx+p);
       }
       return ans;
    }
};