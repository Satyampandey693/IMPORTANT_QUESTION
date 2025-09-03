class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // map<int,int> mp;
        deque<int> q;
        int j=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
          int n=nums[i];
          while(!q.empty()&&q.back()<=i-k){
            q.pop_back();
          }
          while(!q.empty()&&nums[q.front()]<=n) q.pop_front();
          q.push_front(i);
        //   if(q.empty())q.push_back(n);
         if(i>=k-1)
           ans.push_back(nums[q.back()]);

        }

        return ans;
    }
};