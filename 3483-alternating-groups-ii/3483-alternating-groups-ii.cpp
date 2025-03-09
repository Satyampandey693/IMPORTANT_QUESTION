class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        deque<int> dq;
        int n=nums.size();
        int ans=0;
        int f=0;
        for(int i=1;i<nums.size();i++){
            if(nums[(i+n)%n]==nums[(i-1+n)%n]){
                dq.push_back(i);
                continue;
            }
            if(i>=k-1){
                if(dq.empty()) {ans++;f=i;}
                else if(i-dq.back()+1>=k){ ans++;f=i;}
            }
            
}
        // cout<<ans<<" ";
        if(nums[n-1]==nums[0]) dq.push_back(0);
        // if(f==nums.size()-1) return ans;
        for(int i=0;i<k-1;i++){
             if(nums[(i+n)%n]==nums[(i-1+n)%n]){
                dq.push_back(i);
                break;
            }
              int l=i+1;
              //       l+=n-f-1;
            // cout<<l<<" ";
            if(dq.empty()) ans++;
               else{
                    l=i+1;
                    if(dq.back()>i)
                    l+=n-dq.back();
                    if(dq.back()<i)
                        l+=i-dq.back()+1;
                        
                    if(l>=k) ans++;
                    // cout<<ans;
                }
        
           
}
//          for(int i=0;i<nums.size();i++){
             
//              int j=1;
//              for(int j=1;j<k;j++){
//                  if(nums[i])
//              }
            // if(i>=k-1){
            //     if(dq.empty()) ans++;
            //     else if(i-dq.back()+1>=k) ans++;
            // }
            // if(nums[(i+n)%n]==nums[(i-1+n)%n]){
            //     dq.push_back(i);
            // }
// }
     
        return ans;
        
    }
};