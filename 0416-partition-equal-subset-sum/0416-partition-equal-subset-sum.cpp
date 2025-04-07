class Solution {
public:
bool check(int i,int k,vector<int> &arr,vector<vector<int>> &dp){
        if(k<0) return false;
        if(k==0) return true;
        
        if(i==0){
                if(arr[i]==k) return true;
                return false;
        }
        if(dp[i][k]!=-1) return dp[i][k];

bool t=false;
bool nt=false;
        //take
        t=check(i-1,k-arr[i],arr,dp);

        //not take
        nt=check(i-1,k,arr,dp);


        return dp[i][k]=nt|t;
        

}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return check(n-1,k,arr,dp);

}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum&1) return false;
        return  subsetSumToK(nums.size(),sum/2,nums);
    }
};