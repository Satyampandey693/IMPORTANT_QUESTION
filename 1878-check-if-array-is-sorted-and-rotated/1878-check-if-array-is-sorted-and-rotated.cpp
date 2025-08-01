class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size()==1) return true;
        // bool p=0;
        int i=1;
        for(;i<nums.size();i++){
           if(nums[i]<nums[i-1])   break;
        }
        if(i<nums.size())
        if(nums[i]>nums[0]) return false;;
        i++;
        for(;i<nums.size();i++){
            if(nums[i]<nums[i-1]||nums[i]>nums[0]) return false;
        }
        return true;
    }
};