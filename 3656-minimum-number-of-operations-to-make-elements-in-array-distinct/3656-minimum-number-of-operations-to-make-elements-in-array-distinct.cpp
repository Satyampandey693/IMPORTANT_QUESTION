class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int> mp;
        int p=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(mp.find(nums[i])!=mp.end()){
                p=i+1;
                break;
            }
            mp[nums[i]]++;
        }
        return ceil(p/3.0);
    }
};