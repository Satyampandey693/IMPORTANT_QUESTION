class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       vector<int> mp(101,0);
        int p=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(mp[nums[i]]>0){
                p=i+1;
                break;
            }
            mp[nums[i]]++;
        }
        return ceil(p/3.0);
    }
};