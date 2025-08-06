class Solution {
public:
vector<vector<int>> ans;
void find(int i,int k,vector<int> &v, int target){
    
    if(k==0) {
    if(target==0) {
        ans.push_back(v);
        return ;
    }
    return ;
    }
    if(target<0) return ;
   

    for(int j=i;j<10;j++){
        
        v.push_back(j);
        find(j+1,k-1,v,target-j);
        v.pop_back();
         
    }


}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
       find(1,k,v,n) ;
       return ans;
    }
};