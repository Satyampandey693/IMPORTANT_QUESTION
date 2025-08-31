class Solution {
public:
#define ll long long 
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
         vector<vector<int>> ans;
         int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++){
                 if(j>i+1&&nums[j]==nums[j-1]) continue;
                map<ll,int> mp;
                int k=j+1;
           while(k<n){
                 
                   ll p=target-(1ll*nums[i]+nums[j]+nums[k]);
                   if(mp[p]){
                     
                    ans.push_back({nums[i],nums[j],int(p),nums[k]});
                    int r=k+1;
                    while(r<n&&nums[k]==nums[r]) r++;;
                    // if(r!=k&&k<n&&nums[k]!=nums[k-1]) k--;
                    if(k<n)
                     mp[nums[k]]++;
                    // if(r==k)k++;
                    k=r;
                    // if(r>)
                   }
                   else{
                     mp[nums[k]]++;
                     k++;
                     }
                //    
                  
                   
                  
             }
            }
        }
        return ans;
        
    }
};