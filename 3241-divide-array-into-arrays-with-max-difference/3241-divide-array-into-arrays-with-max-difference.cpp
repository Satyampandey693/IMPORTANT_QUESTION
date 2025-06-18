class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mx=0;
        int mn=INT_MAX;
        int i=0;
        int n=nums.size();
        vector<vector<int>> ans;
        while(i<n){
            int j=i;
            mn=nums[j];
            mx=nums[j];
            vector<int> v;
             while(j<n&&j<i+3&&(mx-mn)<=k){
                v.push_back(nums[j]);
               j++;
               if(j<n){
               mx=max(mx,nums[j]);
               mn=min(mn,nums[j]);}
               
             }
             if(v.size()==3){
                ans.push_back(v);
                i=j;
             }
             else return {};
        }
        return ans;
    }
};