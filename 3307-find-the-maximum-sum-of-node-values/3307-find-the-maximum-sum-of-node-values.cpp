class Solution {
public:
typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        // vector<vector<long long>> memo(nums.size(), vector<long long>(2, -1));
        // return maxSumOfNodes(0, 1, nums, k, memo);

     ll idSum=0;
     int c=0;
     int minDec=INT_MAX;
     int minInc=INT_MAX;
     int n=nums.size();
     for(int i=0;i<n;i++){
     if((nums[i]^k)>=nums[i]){
        idSum+=nums[i]^k;
        // cout<<i<<" "<<(nums[i]^k)<<" "<<nums[i];
        minInc=min(minInc,(nums[i]^k)-nums[i]);
        c++;
     }
     else{
        // cout<<i<<" "<<(nums[i]-(nums[i]^k))<<endl;
        idSum+=nums[i];
        minDec=min(minDec,nums[i]-(nums[i]^k));
     }
     }
     if(c&1){
        // cout<<minInc<<" "<<minDec;
       if(minInc>=minDec)
        return idSum-minDec;
       return idSum-minInc;
     }
     else return idSum;

    }

private:
    long long maxSumOfNodes(int index, int isEven, vector<int>& nums, int k,
                            vector<vector<long long>>& memo) {
        if (index == nums.size()) {
            // If the operation is performed on an odd number of elements return
            // INT_MIN
            return isEven == 1 ? 0 : INT_MIN;
        }
        if (memo[index][isEven] != -1) {
            return memo[index][isEven];
        }
        // No operation performed on the element
        long long noXorDone =
            nums[index] + maxSumOfNodes(index + 1, isEven, nums, k, memo);
        // XOR operation is performed on the element
        long long xorDone = (nums[index] ^ k) +
                            maxSumOfNodes(index + 1, isEven ^ 1, nums, k, memo);

        // Memoize and return the result
        return memo[index][isEven] = max(xorDone, noXorDone);
    }
};