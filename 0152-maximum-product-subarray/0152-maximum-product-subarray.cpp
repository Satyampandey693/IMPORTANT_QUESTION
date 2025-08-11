class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=1;
        int f=0;
        int ans=-10;;
        // vector<int> sum(n,0);
        for(int i=0;i<nums.size();i++){
               mx=mx*nums[i];
                 if(mx<0){
                  if(f!=0){
                int p=mx/f;
                ans=max(ans,p);
                  }
               }
               ans=max(ans,mx);
               if(mx<0&&f==0) f=mx;
               if(mx==0){
                 f=mx;
                mx=1;
               
               }
              
        }
        cout<<mx<<" "<<f;
        //  if(mx<0){
        //           if(f!=0&&f!=mx){
        //         int p=mx/f;
        //         ans=max(ans,p);
        //           }
        //        }
        return ans;
    }
};