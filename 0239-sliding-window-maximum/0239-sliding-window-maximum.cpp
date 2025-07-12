class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // map<int,int> mp;
        deque<int> p;
        int j=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            // mp[nums[i]]++;
            // while(!p.empty()&&p.front()<i-k+1) p.pop_front();
           while (!p.empty() && nums[p.back()] < nums[i]) {
    p.pop_back();
}

            p.push_back(i);
            while(!p.empty()&&p.front()<i-k+1) p.pop_front();
            // if(i>=k){
            //   mp[nums[j]]--;
            //   if( mp[nums[j]]==0) mp.erase(nums[j]);
            //   j++;
            // //   if(mp.find(nums[j])==mp])
            // }
           if(i>=k-1){
            int mx=nums[p.front()];
            ans.push_back(mx);}
        }
        return ans;
    }
};