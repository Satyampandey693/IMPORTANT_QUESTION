class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
    //    unordered_map<int,int> bx;
    vector<int> bx(1000+1,0);
        // map<int,int> k;
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
            if(bx[j]){
                bx[j]=0;
                q.push(j);

            }
            else{
               status[j]=1;
            }
          }
          for(auto j:containedBoxes[i]){
            if(status[j]==1) {
                q.push(j);
                continue;
            }
            // if(k.find(j)!=k.end()){
            //        q.push(j);
            //        k.erase(j);
            // }
            // else{
                bx[j]++;
            // }
          }
    // cout<<ans<<" ";
        }
        return ans;
    }
};