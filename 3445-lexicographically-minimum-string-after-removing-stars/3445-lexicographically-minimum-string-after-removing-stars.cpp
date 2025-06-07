class Solution {
public:
    string clearStars(string s) {
        vector<int> c(26,0);
        vector<int> rm;
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        map<int,vector<int>> mp;
        for(int i=0;i<s.size();i++){
           if(s[i]=='*'){
           
                if(!mp.empty()){
                    int t=(*mp.begin()).first;
                    int r=(*mp.begin()).second.back();
                    (*mp.begin()).second.pop_back();
                    if((*mp.begin()).second.size()==0)mp.erase(t);
                    s[r]='-';
                }
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