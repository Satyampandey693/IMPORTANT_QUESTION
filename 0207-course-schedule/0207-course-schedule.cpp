class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> gr[n];
        vector<int> ind(n,0);
        queue<int> q;
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            gr[v].push_back(u);
            ind[u]++;
        }
        for(int i=0;i<n;i++){
            if(ind[i]==0) q.push(i);
        }
        while(!q.empty()){
            int nd=q.front();
            q.pop();
            for(int i:gr[nd]){
                ind[i]--;
                if(ind[i]==0) q.push(i);
            }
        }
        for(int i=0;i<n;i++){
            if(ind[i]!=0) return false;
        }
        return true;

    }
};