class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> mp;
        int j=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(i>=k){
              mp[nums[j]]--;
              if( mp[nums[j]]==0) mp.erase(nums[j]);
              j++;
            //   if(mp.find(nums[j])==mp])
            }
           if(i>=k-1){
            int mx=(*mp.rbegin()).first;
            ans.push_back(mx);}
        }
        return ans;
    }
};