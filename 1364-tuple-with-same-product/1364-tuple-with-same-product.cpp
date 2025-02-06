class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int> mp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(mp[nums[i]*nums[j]])
                ans+=mp[nums[i]*nums[j]]*8;
                mp[nums[i]*nums[j]]++;
            }
        }
        return ans;
    }
};