class Solution {
public:
vector<vector<long long>> dp;
long long  find(int n,vector<int> gr[],vector<int> &val,int sel,int par){
   
    long long t=0;
   if(dp[n][sel]!=-1) return dp[n][sel];
   
    for(auto i: gr[n]){
        if(par==i) continue;
        
             long long  p=0;
              if(!sel){
           long long r= find(i,gr,val,!sel,n);
             p=max(p,r);
            }
            
            long long q=val[i]+find(i,gr,val,sel,n);
            if(gr[i].size()==1){
                if(sel==0)
                q-=val[i];
            }
            t+=max(p,q);
        
    }
    

    
    return dp[n][sel]=t;

}
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        // int p=*min_element(values.begin(),values.end());
        // long long sum=accumulate(values.begin(),values.end(),0);
        int n=values.size();
        vector<int> gr[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            gr[u].push_back(v);
            gr[v].push_back(u);

        }
        dp.resize(n,vector<long long>(2,-1));
       
       return max(find(0,gr,values,1,0), values[0]+find(0,gr,values,0,0)) ;
       
        
    }
};