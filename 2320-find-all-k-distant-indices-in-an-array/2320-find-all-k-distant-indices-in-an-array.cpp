class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int> v(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=key) continue;
            int ind=max(0,i-k);
            v[ind]++; 
            v[i+1]--;
            ind=min(n-1,i+k);
            v[i]++;
            v[ind+1]--;
        }
        vector<int> ans;
        // bool p=false;
        if(v[0])ans.push_back(0);
       for(int i=1;i<n;i++){
        cout<<v[i]<<" ";
        v[i]+=v[i-1];
        
        if(v[i]) ans.push_back(i);
       }
     
       return ans;

    }
};