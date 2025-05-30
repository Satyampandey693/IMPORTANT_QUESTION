class Solution {
public:
vector<int> traverse(vector<int> gr[],int n,int nd){
    queue<pair<int,int>> q;
    vector<int> vis(n,0);
    vector<int> dis(n,1e9);
    dis[nd]=0;
    q.push({nd,0});
    while(!q.empty()){
     int node=q.front().first;
     int d=q.front().second;
     q.pop();
     for(int i:gr[node]){
        if(dis[i]==1e9){
              dis[i]=d+1;
              q.push({i,d+1});
        }
     }
    }
    return  dis;


}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> gr[n];
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)
            gr[i].push_back(edges[i]);
        }
        vector<int> d1=traverse(gr,n,node1);
        vector<int> d2=traverse(gr,n,node2);
        int ans=1e9;
        int node=1e9;
        for(int i=0;i<n;i++){
            int p=max(d1[i],d2[i]);
            if(p!=1e9){
               if(ans>p){
                node=i;
                ans=p;
               }
              
            }
        }
        if(ans!=1e9)
        return node;
        return -1;
        
    }
};