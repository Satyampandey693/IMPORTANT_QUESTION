class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        vector<int> v=nums;;
         sort(nums.begin(),nums.end());

        vector<int> ans;
        map<int,int>mp;
        for(int i=nums.size()-k;i<nums.size();i++){
           mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[v[i]]>0)ans.push_back(v[i]);
            mp[v[i]]--;
        }
        return ans;
    }
};