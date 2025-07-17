class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> arr(n,vector<int> (k,1));
        for(int i=0;i<n;i++){
          for(int j=0;j<i;j++){
            int mod=(nums[i]+nums[j])%k;
            arr[i][mod]=max(arr[i][mod],1+arr[j][mod]);
          }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                ans=max(ans,arr[i][j]);
            }
        }
        return ans;
    }
};