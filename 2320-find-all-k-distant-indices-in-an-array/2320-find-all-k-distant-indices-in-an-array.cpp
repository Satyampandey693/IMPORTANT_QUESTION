class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int> v(nums.size()+1,0);
        int j=0;
          vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=key) continue;
            int ind=max(0,i-k);
            // v[ind]++; 
            // v[i+1]--;
            j=max(j,ind);
            ind=min(n-1,i+k);
            // v[i]++;
            // v[ind+1]--;
            
            while(j<=ind){
               ans.push_back(j);
               j++;  
            }
        }
      
        // bool p=false;
    //     if(v[0])ans.push_back(0);
    //    for(int i=1;i<n;i++){
    //     cout<<v[i]<<" ";
    //     v[i]+=v[i-1];
        
    //     if(v[i]) ans.push_back(i);
    //    }
     
       return ans;

    }
};