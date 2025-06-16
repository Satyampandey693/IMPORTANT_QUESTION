class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mx=-1;
        int ans=-1;
        for(int i=nums.size()-1;i>=0;i--){
              if(mx!=-1){
                ans=max(mx-nums[i],ans);
              }
              mx=max(mx,nums[i]);
              cout<<mx<<endl;
        }
        if(ans==0) return -1;
        return ans;
    }
};