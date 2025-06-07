class Solution {
public:
    string clearStars(string s) {
       
        map<int,vector<int>> mp;
        for(int i=0;i<s.size();i++){
           if(s[i]=='*'){
           
                    int t=(*mp.begin()).first;
                    int r=(*mp.begin()).second.back();
                    (*mp.begin()).second.pop_back();
                    if((*mp.begin()).second.size()==0)mp.erase(t);
                    s[r]='-';
              
           }
           else{
            mp[s[i]-'a'].push_back(i);
           }
        }
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'&&s[i]!='-')
            ans.push_back(s[i]);
        }
        return ans;
    }
};