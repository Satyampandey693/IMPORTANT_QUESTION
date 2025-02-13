class Solution {
public:
#define ll long long 
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>, greater<ll>> pq;
        for(int i=0;i<nums.size();i++) pq.push(nums[i]);
        int ans=0;
        while(!pq.empty()&&pq.top()<k&&pq.size()>1){
             ans++;
             ll p=pq.top();
             pq.pop();
             ll q=pq.top();
             pq.pop();
             ll r=min(p,q)*2+max(p,q); 
             pq.push(r);            

        }
        return ans;

    }
};