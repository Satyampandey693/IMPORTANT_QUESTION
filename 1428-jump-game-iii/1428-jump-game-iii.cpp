class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> gr[n];
        for(int i=0;i<arr.size();i++){
            int u=arr[i];
           if(i+u<n){
            gr[i].push_back(i+u);
           }
           if(i-u>=0) gr[i].push_back(i-u);
        }
        queue<int> q;
        q.push(start);
        vector<int> vis(n,0);
        vis[start]=1;
        while(!q.empty()){
            int nd=q.front();
            q.pop();
            if(arr[nd]==0) return true;
            for(auto i:gr[nd]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=1;
                }
            }

        }
        return false;

    }
};