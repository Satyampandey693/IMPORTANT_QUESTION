class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int ans = arr[0];

        int dp0 = arr[0]; 
        int dp1 = 0;      

        for (int i = 1; i < n; ++i) {
            dp1 = max(dp0, dp1 + arr[i]);     
            dp0 = max(dp0 + arr[i], arr[i]);  
            ans = max({ans, dp0, dp1});
        }

        return ans;
    }
};
