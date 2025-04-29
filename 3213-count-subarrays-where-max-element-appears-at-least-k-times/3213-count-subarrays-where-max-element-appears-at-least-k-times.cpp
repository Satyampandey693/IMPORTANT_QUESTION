class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
         map<int ,long long>m;
        long long ans=0;
        int l=0;
int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;   
            if(m[maxi]>=k){
                while(l<=i&&m[maxi]>=k){
                    m[nums[l]]--;
                    l++;
                    ans+=(n-i);
                    cout<<(n-i)<<" ";
                } 
            }  
           
            }
            return ans;
    }
};