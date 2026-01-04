class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int c=0;
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j!=0) continue;
                c++;
                if(nums[i]/j!=j) c++;
            }
            if(c==4)
            {
               for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j!=0) continue;
               ans+=j;
                if(nums[i]/j!=j)  ans+=(nums[i]/j);
            }  
            }

        }
        return ans;
    }
};