class Solution {
public:
    int numberOfArrays(vector<int>& nums, int lower, int upper) {
        // vector<int> poss(n);
        int l=lower;int r=upper;
        int n=nums.size();
        
        int i=0;
        int ans=INT_MAX;
        while(i<n){
            if(nums[i]>0){
                int nl=l+nums[i];
                int nr=min(upper,r+nums[i]);
                if(nr<nl){
                    cout<<i;
                    return 0;}
                int p=nr-nl+1;
                ans=min(ans,p);
                l=nl;
                r=nr;
            }
            else if(nums[i]<0){
               int nl=max(lower,l+nums[i]);
               int nr=r+nums[i];
               if(nr<nl){
                cout<<i;
                 return 0;}
               int p=nr-nl+1;
               ans=min(ans,p);
               l=nl;
               r=nr;

            }
            else{
                 int p=r-l+1;
               ans=min(ans,p);
            } 
            

            i++;
        }
        
        // cout<<ans;
        return ans;
    }
};