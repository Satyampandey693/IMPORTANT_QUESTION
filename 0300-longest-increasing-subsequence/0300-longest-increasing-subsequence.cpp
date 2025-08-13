class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> st;
        int ans=1;
        for(int i=0;i<nums.size();i++){
            auto it=lower_bound(st.begin(),st.end(),nums[i]);
             if(it!=st.end()){
                  st.erase(*it);
                  st.insert(nums[i]);
             }
             else{
                st.insert(nums[i]);
             }
             int sz=st.size();
             ans=max(ans,sz);
        }
        return ans;
    }
};