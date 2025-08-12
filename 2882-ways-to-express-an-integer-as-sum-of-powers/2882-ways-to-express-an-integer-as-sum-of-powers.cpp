class Solution {
public:
int mod=1e9 + 7;
    int calculate(int n,int x,int i,long long r, vector<vector<int>> &dp){
         if(r==n){
            return 1;
           }
        if(r>n||i>n) return 0;
       
        if(dp[i][r]!=-1) return dp[i][r];
        
       
        int p,q;
         //exclude
        p=calculate(n,x,i+1,r,dp);
        r+=(long long)pow(i,x);
        q=calculate(n,x,i+1,r,dp);
        r-=(long long)pow(i,x);
       
      
        return  dp[i][r]=(p%mod+q%mod)%mod;
        
        
    }
    int numberOfWays(int n, int x) {
       long long r=0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int prev=0;
        return calculate(n,x,1,r,dp);
    }
};