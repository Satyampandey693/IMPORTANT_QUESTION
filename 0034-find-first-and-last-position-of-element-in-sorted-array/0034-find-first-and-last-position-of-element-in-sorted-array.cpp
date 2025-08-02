class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int up=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        int lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(lb==up) return {-1,-1};
        return {lb,up-1};

    }
};