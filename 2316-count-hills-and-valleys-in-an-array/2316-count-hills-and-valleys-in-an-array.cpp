class Solution {
public:
    int countHillValley(vector<int>& nums) {
  int i=1;int n=nums.size();
  int ans=0;
  while(i<n-1){
    int j=i+1;
    while(j<n&&nums[j]==nums[j-1])j++;
    if(j!=n){
        if(nums[i]>nums[i-1]&&nums[i]>nums[j]) ans++;
        else if(nums[i]<nums[i-1]&&nums[i]<nums[j]) ans++;
    }
    i=j;

  }
  return ans;
    }
};