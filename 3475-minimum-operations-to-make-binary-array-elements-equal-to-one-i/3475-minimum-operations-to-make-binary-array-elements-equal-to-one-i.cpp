class Solution {
public:
    int minOperations(vector<int>& nums) {
       int i=0;
       int ans=0;
       int n=nums.size();
       while(i<n){
        if(nums[i]==1){
            i++;
            continue;
        } 
        else{
            ans++;
            if(i+2>=n)return -1;
            nums[i]=!nums[i];
             nums[i+1]=!nums[i+1];
              nums[i+2]=!nums[i+2];
        }
       } 
       return ans;
    }
};