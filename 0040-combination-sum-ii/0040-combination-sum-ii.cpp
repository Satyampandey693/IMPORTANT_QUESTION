class Solution {
public:
vector<vector<int>> ans;
void find(int i,vector<int> &v,vector<int>& candidates, int target){
     if(target==0) {
        ans.push_back(v);
        return ;
    }
    if(i>=candidates.size()) return;
    if(target<0) return ;
   
    // //not pick
    //  find(i+1,v,candidates,target);
    // //pick
    // v.push_back(candidates[i]);
    // find(i,v,candidates,target-candidates[i]);
    // v.pop_back();
    //
    //  find(i+1,v,candidates,target);
    for(int j=i;j<candidates.size();j++){
        if(j>i&&candidates[j]==candidates[j-1]) continue;
        v.push_back(candidates[j]);
        find(j+1,v,candidates,target-candidates[j]);
        v.pop_back();
         
    }


}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());

        vector<int> v;
        find(0,v,candidates,target);
        return ans;
    }
};