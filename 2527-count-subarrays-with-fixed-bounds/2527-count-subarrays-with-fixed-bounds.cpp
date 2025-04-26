// class Solution {
// public:

//     long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       
//         int l=0,r=0;
//         int maxi=nums[0];
//         int mini=nums[0];
        
//         while(r<nums.size()){
//          if(mini==minK&&maxi==maxK){
//             ans++;
//          }
         
//         } 
//         return ans;

//     }
// };
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int bad_idx = -1, left_idx = -1, right_idx = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (!(minK <= nums[i] && nums[i] <= maxK)) {
                bad_idx = i;
            }

            if (nums[i] == minK) {
                left_idx = i;
            }

            if (nums[i] == maxK) {
                right_idx = i;
            }

            res += max(0, min(left_idx, right_idx) - bad_idx);
        }

        return res;
    }
};