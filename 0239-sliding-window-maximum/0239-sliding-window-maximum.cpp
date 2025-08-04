class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // map<int,int> mp;
        deque<int> p;
        int j=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
           while(!p.empty()&&nums[p.back()]<nums[i]){
             p.pop_back();
           }
           p.push_back(i);
           while(!p.empty()&&p.front()<=i-k) p.pop_front();
           if(i>=k-1)
           ans.push_back(nums[p.front()]);
        }

        return ans;
    }
};