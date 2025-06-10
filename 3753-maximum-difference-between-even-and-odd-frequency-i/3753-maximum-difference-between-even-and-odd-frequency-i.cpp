class Solution {
public:
    int maxDifference(string s) {
        vector<int> v(26,0);
        for(int i=0;i<s.size();i++) v[s[i]-'a']++;
        int ev=0;
        int odd=0;
         int mnev=INT_MAX;
        int mnodd=INT_MAX;
        
        for(int i=0;i<26;i++){
            if(v[i]==0) continue;
            if(v[i]&1) {
                mnodd=min(mnodd,v[i]);
                odd=max(odd,v[i]);
                }
            else{
                mnev=min(mnev,v[i]);
                ev=max(ev,v[i]);
            }
        }
        // return max(odd-ev,max(odd-mnev,max()))
        // cout<<odd<<mnev;
        return odd-mnev;
    }
};