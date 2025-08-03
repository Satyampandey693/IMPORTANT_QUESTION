class Solution {
public:

    int shipWithinDays(vector<int>& piles, int h) {
        int sum=accumulate(piles.begin(),piles.end(),0*1ll);
        int mx=*max_element(piles.begin(),piles.end());
        int s=mx;
        int e=sum;
        int mid=s+(e-s)/2;
        int ans=mx;
        while(s<=e){
            int tw=0;
            int d=1;
            for(int i=0;i<piles.size();i++){
                // th+=ceil(piles[i]/(double)mid);
                tw+=piles[i];
                 if(tw>mid){
                    d++;
                    tw=piles[i];
                 }

            }

            if(d<=h){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
            mid=s+(e-s)/2;
        }
        return ans;
    }
};