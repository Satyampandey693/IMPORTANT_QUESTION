class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> v(32,0);
        // int i=0;
        // int j=0;
        // int mxor=0;
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     mxor=mxor|nums[i];
        // }
        // int num=0;
        vector<int> ans(n,0);
        // while(i<n){
        //     for(int k=0;k<31;k++){
        //         if((nums[i]>>k)&1){
        //              num=num|(1<<k);
        //              v[k]++;

        //         }
        //     }
        //    while(num==mxor){
        //     ans[j]=i-j+1;
        //     for(int k=0;k<31;k++){
        //         if((nums[j]>>k)&1){
        //             v[k]--;
        //             if(v[k]==0)num=num^(1<<k);
        //         }
        //     }
        //     j++;
        //    }
        //    i++;
        // }
        // return ans;
    for(int i=n-1;i>=0;i--){
             for(int k=0;k<31;k++){
                if((nums[i]>>k)&1){
                     
                     v[k]=i;

                }
            }
           int ind=0;
         for(int k=0;k<31;k++){
              if(v[k]!=0){
                 ind=max(ind,v[k]);
              }
            }
            if(ind==0){
                ans[i]=1;
            }
            else
              ans[i]=ind-i+1;

        }
        return ans;


    }
};