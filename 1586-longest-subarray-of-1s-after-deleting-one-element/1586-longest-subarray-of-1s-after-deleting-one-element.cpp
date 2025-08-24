class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int pro=0;
        int on=0;
        int z=0;
        int prz=0;
        int ans=0;
        int tz=0;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==1){
            on++;
            if(z!=0)
            prz=z;
            z=0;
           }
           else{
            tz++;
            if(prz==1){
                // cout<<i<<endl;
                ans=max(ans,on+pro);
            }
            if(on!=0)
            pro=on;
            on=0;
             z++;
           }
           ans=max(ans,on);
        }
         if(prz==1){
                ans=max(ans,on+pro);
            }
            if(tz==0)ans=ans-1;
            return ans;
    }
};