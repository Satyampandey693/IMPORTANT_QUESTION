class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int oddMax=0;
        int eveMax=0;
        // vector<int> v(nums.size(),0);
        //even
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1){
                //   v[i]=oddMax+1;
                  oddMax++;
            }
            else {
                // v[i]=eveMax+1;
                eveMax++;
            }
        }
        int k=nums[0]&1;
        int mx=1;
        for(int i=1;i<nums.size();i++){
          if((nums[i]&1)){
              if(k==0) {
                k=1;
                mx++;
              }
          }
          else{
             if(k==1) {
                k=0;
                mx++;
              }
          }
        }
        return max(eveMax,max(oddMax,mx));
    }
};