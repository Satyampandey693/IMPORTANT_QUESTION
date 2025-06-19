class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // int c=0;
        // sort(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        vector<int> arr(mx+1,0);
         for(int i=0;i<nums.size();i++){
               arr[nums[i]]++;
        } 
        int c=0;
        int mn=INT_MAX;
        for(int i=0;i<mx+1;i++){
            while(arr[i]==0){
                i++;
                continue;
            }
              mn=min(mn,i);
              if(i-mn<=k)continue;
              c++;
              mn=i;
        }
        // int mx=0;
        // int j=0;
        // int i=0;
        // for(;i<nums.size();i++){
        //         if(nums[i]-nums[j]<=k) continue;
        //         c++;
        //         j=i;
        // }
        c++;
        return c;
    }
};