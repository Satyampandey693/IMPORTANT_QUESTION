class Solution {
public:
#define ll long long
    int minEatingSpeed(vector<int>& piles, int h) {
        ll sum=accumulate(piles.begin(),piles.end(),0*1ll);
        int mx=*max_element(piles.begin(),piles.end());
        int s=ceil(sum/(double)h);
        int e=mx;
        int mid=s+(e-s)/2;
        int ans=mx;
        while(s<=e){
            int th=0;
            for(int i=0;i<piles.size();i++){
                th+=ceil(piles[i]/(double)mid);
            }
            if(th<=h){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
            mid=s+(e-s)/2;
        }
        return ans;
    }
};