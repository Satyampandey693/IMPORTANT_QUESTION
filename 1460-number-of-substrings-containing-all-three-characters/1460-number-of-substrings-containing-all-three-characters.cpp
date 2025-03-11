class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int> m;
        int i=0;
        int n=s.size();
        int j=0;
        int ans=0;
        while(j<n){
            m[s[j]]++;
            // cout<<m.size();
            while(m.size()==3){
                ans+=n-j;
                m[s[i]]--;
                if(m[s[i]]==0)m.erase(s[i]);
                i++;
            }
            j++;
        }
        
        return ans;
    }
};