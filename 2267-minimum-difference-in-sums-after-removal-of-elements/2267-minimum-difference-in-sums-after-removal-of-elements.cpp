class Solution {
public:
#define ll long long 
    long long minimumDifference(vector<int>& nums) {
       //we have to chhose n largest element ,n smallest element
       priority_queue<int,vector<int>,greater<int>> pq;
       int n=nums.size()/3;
       ll s=0;
       vector<ll> arr(3*n,0);
       for(int i=3*n-1;i>=0;i--){
           pq.push(nums[i]);
           s+=nums[i];

           if(pq.size()>n){
             int p=pq.top();
             pq.pop();
             s-=p;
           }

           if(pq.size()==n){
              arr[i]=s;
           }

       }
       ll ans=LLONG_MAX;
       priority_queue<int> maxq; 
       s=0;
       for(int i=0;i<2*n;i++){
        maxq.push(nums[i]);
           s+=nums[i];
         if(maxq.size()>n){
          
             int p=maxq.top();
             maxq.pop();
             s-=p;
           }

           if(maxq.size()==n){
               ans=min(ans,s-arr[i+1]); 
           }

       }
       return ans;
    }
};