class Solution {
public:
    string makeFancyString(string s) {
       string ans;
        int c=1;
        ans.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                c++;

            }
            else {
                // ans+=max(0,c-3);
                c=1;
            }
            if(c<3) ans.push_back(s[i]);
        }
        return ans;
    }
};