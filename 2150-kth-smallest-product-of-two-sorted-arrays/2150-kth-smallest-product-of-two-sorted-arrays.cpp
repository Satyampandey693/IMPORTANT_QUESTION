class Solution {
public:
#define ll long long

ll count(ll target,vector<int>&nums1,vector<int>& nums2){
    ll c=0;
    for(int i=0;i<nums1.size();i++){
        if(nums1[i]==0) {
            if(target>=0)
            c+=nums2.size();
            continue;
        }
        // ll p=nu/nums1[i];
        // int ind=upper_bound(nums2.begin(),nums2.end(),p)-nums2.begin();
        // if(p<0){
        //     int r=upper_bound(nums2.begin(),nums2.end(),-1)-nums2.begin();
        //     c+=ind-r;
        //     continue;
        // }
        // c+=ind;
       int low = 0, high = nums2.size();
       int num1=nums1[i];
            while (low < high) {
                int mid = low + (high - low) / 2;
                ll product =  num1 *1ll* nums2[mid];
                if (product <= target) {
                    if (num1 > 0) low = mid + 1;
                    else high = mid;
                } else {
                    if (num1 > 0) high = mid;
                    else low = mid + 1;
                }
            }
            
            c += (nums1[i] > 0) ? low : nums2.size() - low;
        
    }
    return c;
}
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {

        int n=nums1.size();
        int m=nums2.size(); 
        if(k>m*1ll*n) return -1;
        ll s= -10000000000;
        ll e=10000000000;
        ll ans=-1;
        ll mid=s+(e-s)/2;
        while(s<=e){
          ll p=count(mid,nums1,nums2);
       if(p>=k){
        ans=mid;
        e=mid-1;
       }
       else{
        s=mid+1;
       }
          mid=s+(e-s)/2;
        }
        return ans;
    }
};