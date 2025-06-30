class Solution {
public:
    int findLHS(vector<int>& nums) {
        int i=0,j=1;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        while(i<n){
            while(j<n&&nums[j]-nums[i]<=1){
                  j++;
            }
            if(nums[j-1]-nums[i]==1){
                ans=max(ans,j-i);
            }
          j=max(j,i+1);
          i++;
        }
        return ans;
    }
};