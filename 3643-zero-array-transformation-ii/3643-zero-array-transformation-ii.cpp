class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // vector<int> p;
        int n=queries.size();
        // for(int i=0;i<queries.size();i++){
        //     p.push_back(queries[i][2]);
        // }
        // for(int i=1;i<n;i++){
        //     p[i]+=p[i-1];
        // }
        // int ans=0
        // for(int i=0;i<nums.size();i++){
        //    int ind=lower_bound(p.begin(),p.end(),nums[i])-p.begin();
        //    if(ind==n) return -1;
        //    ans=max(ans,ind);
        // }
        // return ans;
         int i=0;
        int j=0;
        n=nums.size();
        vector<int> sum(n,0);
        int p=0;
        for(;i<n;i++){
            p+=sum[i];
            // cout<<p<<" ";
            while(p<nums[i]&&j<queries.size()){
            int st=queries[j][0];
            int e=queries[j][1];
            sum[st]+=queries[j][2];
            if(e<n-1)
            sum[e+1]-=queries[j][2];
           if(st<=i&&i<=e) p+=queries[j][2];
            j++;
            }
            // cout<<j<<endl;
            if(p<nums[i]&&j>=queries.size()) return -1;
        }
        return j;

    }
};