class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int c=0;
        sort(nums.begin(),nums.end());
        // int mx=0;
        int j=0;
        int i=0;
        for(;i<nums.size();i++){
                if(nums[i]-nums[j]<=k) continue;
                c++;
                j=i;
        }
        c++;
        return c;
    }
};