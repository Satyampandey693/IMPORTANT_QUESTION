class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        map<int,int> bx;
        map<int,int> k;
        queue<int> q;
        int ans=0;
        for(int i=0;i<initialBoxes.size();i++){
            if(status[initialBoxes[i]]==1){
                q.push(initialBoxes[i]);
                // cout<<i;
            }
            else bx[initialBoxes[i]]++;
        }
        while(!q.empty()){
          int i=q.front();
          q.pop();
          ans+=candies[i];
          for(auto j:keys[i]){
            if(bx.find(j)!=bx.end()){
                bx.erase(j);
                q.push(j);

            }
            else{
                k[j]++;
            }
          }
          for(auto j:containedBoxes[i]){
            if(status[j]==1) {
                q.push(j);
                continue;
            }
            if(k.find(j)!=k.end()){
                   q.push(j);
                   k.erase(j);
            }
            else{
                bx[j]++;
            }
          }
    // cout<<ans<<" ";
        }
        return ans;
    }
};