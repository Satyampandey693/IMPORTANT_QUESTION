class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0;
        int temp=0;
        // map<int,int> mp;
        vector<int> mp(1e4+1,0);
        int i=0,j=0;
        int n=nums.size();
        while(i<n){
            if(mp[nums[i]]==0){
                temp+=nums[i];
                mp[nums[i]]++;
            }
            else{
                int p=nums[i];
              while(j<i&&nums[j]!=p){
                    //  mp.erase(nums[j]);
                    mp[nums[j]]--;
                     temp-=nums[j];
                     j++;

            }
            //  temp-=nums[j];
             j++;

            // mp[nums[i]]++;
            }
            ans=max(ans,temp);
            i++;
            
        }
        return ans;

    }
};