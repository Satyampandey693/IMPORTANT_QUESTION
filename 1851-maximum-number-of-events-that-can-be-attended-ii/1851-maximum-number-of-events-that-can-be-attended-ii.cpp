class Solution {
public:
//  auto it = lower_bound(v.begin(), v.end(), target,
//         [](const vector<int>& row, int value) {
//             return row[0] < value;
//         });
 int find(int i,vector<vector<int>>& events,int k,vector<vector<int>> &dp){
    if(k==0) return 0;
    if(i>=events.size()) return 0;
    //skip this event;
    if(dp[i][k]!=-1) return dp[i][k];
    int p=find(i+1,events,k,dp);
    //take this 
    int q=events[i][2];
    int target=events[i][1];
    int it = upper_bound(events.begin()+i+1, events.end(), target,
        [](int value, const vector<int>& row) {
        return value < row[0];  // means: keep moving right while value < row[0]
    })-events.begin();
    q=q+find(it,events,k-1,dp);
      return dp[i][k]= max(p,q);
       }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>> dp(events.size(),vector<int>(k+1,-1));
        return find(0,events,k,dp);

    }
};