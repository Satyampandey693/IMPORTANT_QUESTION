class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int j=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(j<g.size()&&g[j]<=s[i]){
                ans++;
                j++;
            }

            }
        
        return ans;
    }
};