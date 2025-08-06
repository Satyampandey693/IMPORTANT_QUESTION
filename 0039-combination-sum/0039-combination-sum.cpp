class Solution {
public:
vector<vector<int>> ans;
void find(int i,vector<int> &v,vector<int>& candidates, int target){
    if(i>=candidates.size()) return;
    if(target<0) return ;
    if(target==0) {
        ans.push_back(v);
        return ;
    }
    //not pick
     find(i+1,v,candidates,target);
    //pick
    v.push_back(candidates[i]);
    find(i,v,candidates,target-candidates[i]);
    v.pop_back();


}
 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        find(0,v,candidates,target);
        return ans;
    }
};