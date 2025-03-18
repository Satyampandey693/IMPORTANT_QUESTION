class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        vector<int> v(31,0);
        int ans=1;
        int n=nums.size();
        while(i<n){
           for(int t=0;t<31;t++){
            int r=(nums[i]>>t)&1;
            if(r){
                if(v[t]){
                //    cout<<t<<" ";
                    while(j<i){
                        for(int k=0;k<31;k++){
                            int s=(nums[j]>>k)&1;
                            if(s)v[k]--;

                        }
                        j++;
                        if(v[t]==0){
                            break;
                        }
                        
                    }
                }
                 v[t]++;
            }
           
           }
        //    cout<<i<<" "<<j<<endl;
           ans=max(ans,i-j+1);
           i++;
        }
        return ans;
    }
};