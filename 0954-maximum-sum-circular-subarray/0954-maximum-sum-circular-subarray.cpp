class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> p=nums;
        p.insert(p.end(),nums.begin(),nums.end());
        int n=nums.size();
        int j=0;
        int mx=INT_MIN;
        int sum=0;
        int ans=INT_MIN;
        // if(n==1) return nums[0];
    vector<int> lmx(n,0);
    int s=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
          s+=nums[i];
            mx=max(mx,sum);
          lmx[i]=s;
            if(sum<=0){
                sum=0;
            }
        }
        ans=mx;
         vector<int> rmx(n,0);
         sum=0;
         mx=INT_MIN;
         int ind=0;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            // mx=max(mx,sum);
            if(sum>mx){
                ind=i;
                mx=sum;
            }
          rmx[i]=sum;
            if(sum<=0){
                // ind=i;
                // break;
            }
        }
        ans=max(mx,ans);
        // mx=INT_MIN;
        int maxi=INT_MIN;
        for(int i=0;i<n-1;i++){
             maxi=max(maxi,lmx[i]);
            //  cout<<maxi<<" ";
            // if(i!=n-1)
           ans=max(ans,maxi+rmx[i+1]);
          
        }
        ans=max(ans,mx);
        return ans;
        

    }
};