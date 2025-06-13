class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
       int s=0;
       int e=1e9;
       int mid=s+(e-s)/2;
      sort(nums.begin(),nums.end());
      vector<int> arr;
    //   for(int i=1;i<nums.size();i+=2){
    //     arr.push_back(nums[i]-nums[i-1]);
    //   }
      mid=s+(e-s)/2;
      int ans=0;
       while(s<=e){
        int c=0;
        //   for(int i=0;i<nums.size();i++){
        //     //    if(arr[i]<=mid) c++;
        //     if(nums[i])
        //   }
        int i=1;
        while(i<nums.size()){
            if(nums[i]-nums[i-1]<=mid){
                c++;
                i+=2;
            }
            else{
            i++;
            }
        }
          if(c>=p) {ans=mid;
          e=mid-1;}
          else s=mid+1;
        mid=s+(e-s)/2;
       }
       return ans;
    }
};