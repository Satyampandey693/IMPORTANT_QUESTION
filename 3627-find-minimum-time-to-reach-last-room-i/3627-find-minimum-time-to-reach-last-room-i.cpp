class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int m=moveTime.size();
        int n=moveTime[0].size();
        vector<int> delr={0,-1,0,+1};
        vector<int> delc={-1,0,+1,0};
        vector<vector<int>> vis(m,vector<int>(n,0));
        vis[0][0]=1;
        while(!pq.empty()){
            int t=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
           
            pq.pop();
            if(r==m-1&&c==n-1) return t;
            for(int i=0;i<4;i++){
                    int nr=r+delr[i];
                    int nc=c+delc[i];
                    if(nr>=0&&nr<m&&nc>=0&&nc<n&&!vis[nr][nc]){
                         vis[nr][nc]=1;
                        int nt=max(t,moveTime[nr][nc])+1;
                        pq.push({nt,{nr,nc}});
                    }
                
            }
        }
        return -1;
    }
};