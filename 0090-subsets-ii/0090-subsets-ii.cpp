class Solution {
public:
vector<vector<int>> ans;
void find(int i,vector<int> &v,vector<int>& candidates){
     
    if(i>=candidates.size()) {
        ans.push_back(v);
        return ;
    }
   
   
//    find(i+1,v,candidates);
ans.push_back(v);
    for(int j=i;j<candidates.size();j++){
        if(j>i&&candidates[j]==candidates[j-1]) continue;
        v.push_back(candidates[j]);
        find(j+1,v,candidates);
        v.pop_back();
         
    }


}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<int> v;
        find(0,v,nums);
        return ans;

    }
};