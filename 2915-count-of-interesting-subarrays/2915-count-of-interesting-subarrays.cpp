class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        
        long long ans=0;
        unordered_map<int,int> m;
        m[0]++;
        int i=0;
        int j=0;
        int cnt=0;
        int prev=0;
        while(i<nums.size()){
            if(nums[i]%modulo==k){
                cnt++;

            }
            if(m.find((cnt-k+modulo)%modulo)!=m.end()){//adding modulo because subtraction may negative and we 
            // are taking modulo 
                ans+=m[(cnt-k+modulo)%modulo];
            }
            m[cnt%modulo]++;
            i++;
            
            
}
return ans;
    }
};