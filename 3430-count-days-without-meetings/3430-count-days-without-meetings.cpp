class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int ans=0;
        int mx=0;
        for(int i=0;i<meetings.size();i++){
          
            ans+=max(0,meetings[i][0]-mx-1);
            mx=max(mx,meetings[i][1]);
            

        }
        ans+=max(0,days-mx);
        return ans;
    }
};