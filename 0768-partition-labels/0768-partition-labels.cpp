class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v(26,0);
        int n=s.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        v[s[i]-'a']=i;
        int maxi=0;
        int t=0;
        for(int i=0;i<n;i++){
            if(maxi<i){
                
                if(ans.size()<1)
                ans.push_back(i);
                else{
                    ans.push_back(i-t);
                }
                t=i;}
            maxi=max(maxi,v[s[i]-'a']);
        }
        if(!ans.empty()){
           int p=n-t;
          ans.push_back(p);
        }
        else ans.push_back(n);
        // cout<<ans.size();
        
        return ans;
    }
};