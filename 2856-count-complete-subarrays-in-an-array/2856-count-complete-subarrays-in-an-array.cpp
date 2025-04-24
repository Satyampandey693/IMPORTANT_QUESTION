class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
}
        int ans=0;
        int d=m.size();
        // cout<<d;
        for(int i=0;i<nums.size();i++){
         unordered_map<int,int> mp;
            for(int j=i;j<nums.size();j++){
                mp[nums[j]]++;
                if(mp.size()==d)ans++;
            }
              // if(mp.size()==d)ans++;
}
        return ans;
    }
};