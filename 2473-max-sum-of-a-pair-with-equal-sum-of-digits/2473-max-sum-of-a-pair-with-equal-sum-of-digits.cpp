class Solution {
public:
int dgSum(int n){
    int ans=0;
    while(n){
        ans+=n%10;
        n/=10;

    }
    return ans;
}
    int maximumSum(vector<int>& nums) {
        map<int,int> m;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int p=dgSum(nums[i]);
            if(m[p]){
                // cout<<i<<" "<<p<<" "<<m[p]<<" "<<nums[i]<<endl;
                ans=max(ans,m[p]+nums[i]);

            }
            if(m[p]){
                m[p]=max(m[p],nums[i]);
            }
            else m[p]=nums[i];
        }
        return ans;
    }
};