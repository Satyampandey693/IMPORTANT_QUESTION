class Solution {
public:
#define ll long long
vector<vector<int>> dp;
vector<long long> ans;
void find(int n,int par,vector<int> graph[],vector<int>& cost){
    for(auto i:graph[n]){
        if(i!=par){
            find(i,n,graph,cost);
        }
    }
    vector<int> p;
    p.push_back(cost[n]);
    for(auto i:graph[n]){
        if(i!=par){
            vector<int> a=dp[i];
             p.insert(p.end(),a.begin(),a.end());
        }
    }
    sort(p.begin(),p.end(),greater<int>());
    int sz=p.size();
    if(p.size()<3){
        ans[n]=1;
        dp[n]=p;
        return ;
    }
    if(p[1]*1ll*p[2]>p[sz-1]*p[sz-2]){
        ans[n]=p[0]*1ll*p[1]*1ll*p[2];
    }
    else{
        ans[n]=p[0]*1ll*p[sz-1]*p[sz-2];
    }
    if(ans[n]<0) ans[n]=0;
    if(p.size()<=5) dp[n]=p;
    else{
        dp[n]={p[0],p[1],p[2],p[sz-1],p[sz-2]};
    }
    return ;
}
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n=cost.size();
        dp.resize(n);
       
        ans.resize(n);
        vector<int> graph[n];
        for(int i=0;i<edges.size();i++)
{
    int a=edges[i][0];
    int b=edges[i][1];
    graph[a].push_back(b);
     graph[b].push_back(a);

}        
find(0,-1,graph,cost);
// sort(cost.begin(),cost.end());
// for(int i=cost.size()-3;i<cost.size();i++)cout<<cost[i]<<" ";
return ans;

    }
};