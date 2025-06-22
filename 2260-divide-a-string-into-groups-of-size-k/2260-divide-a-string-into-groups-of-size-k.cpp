class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int i=0;
        vector<string> ans;
        if(s.size()<k){
             string p=s.substr(i);;
            while(p.size()<k) p.push_back(fill);
        ans.push_back(p);
        return ans;
        }
        for(;i<=s.size()-k;i+=k){
             string p=s.substr(i,k);
             ans.push_back(p);
        }
        if(i<s.size()){
            string p=s.substr(i);;
            while(p.size()<k) p.push_back(fill);
        ans.push_back(p);

        }
        
        return ans;
    }
};