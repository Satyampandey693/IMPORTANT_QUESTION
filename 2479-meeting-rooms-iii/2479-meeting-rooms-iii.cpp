class Solution {
public:
#define ll long long
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> v(n,0);
        sort(meetings.begin(),meetings.end());
        int t=meetings[0][0];
        int j=0;
        priority_queue<ll,vector<ll>,greater<ll>> room;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> busy;
        for(int i=0;i<n;i++)room.push(i);
        while(j<meetings.size()){
           int st=meetings[j][0];
           int e=meetings[j][1];
           while(!busy.empty()&&busy.top().first<=st){
            room.push(busy.top().second);
            busy.pop();
           }
          if(!room.empty()){
            int r=room.top();
            busy.push({meetings[j][1],r});
             v[r]++;
          room.pop();
          }
          else{
               auto [availTime, room] = busy.top(); busy.pop();
                busy.emplace(availTime + 1ll*(e - st), room);
                v[room]++;

          }
          j++;
          
        }
        int mx=0;
        int ans=0;
        for(int i=0;i<n;i++){
            // cout<<v[i]<<" ";
          if(mx<v[i]){
           ans=i;
           mx=v[i];
          }
        }
        return ans;

    }
};