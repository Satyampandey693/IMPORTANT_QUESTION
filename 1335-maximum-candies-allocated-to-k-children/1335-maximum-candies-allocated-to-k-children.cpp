class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int s=0;
        int e=1e9;
        int ans=0;
        int mid=(s+(e-s)/2);
        while(s<=e){
        //    cout<<mid<<endl; 
         long long  p=0;
         if(mid==0){
            s=mid+1;
            mid=s+(e-s)/2;
         }
        cout<<mid<<endl;
         for(int i=0;i<candies.size();i++){
            p+=candies[i]/mid;
         }
         if(p>=k){
            ans=mid;
            s=mid+1;
         }
         else e=mid-1;
          mid=(s+(e-s)/2);
        }
        return ans;
    }
};