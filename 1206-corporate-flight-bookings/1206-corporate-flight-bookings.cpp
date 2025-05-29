class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& queries, int n) {
                vector<int> d(n+1,0);
        for(int i=0;i<queries.size();i++){
            d[queries[i][0]-1]+=queries[i][2];
            d[queries[i][1]]-=queries[i][2];

        }
        for(int i=1;i<n;i++){
          d[i]+=d[i-1];
        }
        d.pop_back();
        return d;
    }
};