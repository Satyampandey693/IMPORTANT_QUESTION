class Solution {
public:
vector<int> vis;
int findBtime(vector<int> graph[],int b,vector<int> &bt,int n){
    vis[n]=1;
    if(n==b){
        bt[b]=0;
        return 1;
    }
int p=0;
for(auto nt:graph[n]){
    if(!vis[nt]){
        int r=findBtime(graph,b,bt,nt);
        if(r!=0)
        p=max(p,1+r);
    }
}
if(p!=0){
    bt[n]=p-1;
}
return p;
}
int ans=INT_MIN;
void findMax(vector<int> graph[],int n,vector<int> &amount,vector<int> &bt,int s,int t){
     vis[n]=1;
if((graph[n].size()==1)&&(n!=0)){
    // if(amount[n]>=0)s+=amount[n];
    // else s-=amount[n];
    cout<<"h";
ans=max(ans,s);
return ;
}
for(auto nt:graph[n]){
    int r=s;
    if(!vis[nt]){
        if(bt[nt]!=1e9){
            if(t+1==bt[nt]){
                 s+=amount[nt]/2;
            }
            else if(t+1<bt[nt]){
                s+=amount[nt];
            }
        }
        else{
        s+=amount[nt];
    
        }
       
        findMax(graph,nt,amount,bt,s,t+1);
    }
    s=r;
}


}
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<int> bt(n,1e9);//bob time 
        vector<int> graph[n];
        for(int i=0;i<n-1;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // if(2<n)
        // cout<<graph[2].size();
        vis.resize(n,0);
        findBtime(graph,bob,bt,0);
        // cout<<bt[0]<<" "<<bt[1]<<endl;
        int s=0;
        fill(vis.begin(), vis.end(), 0);  // Reset vis array to all 0s
        if(bob!=0)
       s+=amount[0];
       else s+=amount[0]/2;
    
        findMax(graph,0,amount,bt,s,0);
        return ans;

    }
};