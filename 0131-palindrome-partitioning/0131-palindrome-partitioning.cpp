class Solution {
public:
vector<vector<string>> ans;
void find(int i,vector<string>&v,string &s){
   
    if(i>=s.size())  {
        if(!v.empty())
        ans.push_back(v);
        return ;
    }
   
//    int p=s[i]-'2';
   string r;
    for(int j=i;j<s.size();j++){
       
        r.push_back(s[j]);
        string p=r;
        reverse(p.begin(),p.end());
        if(p==r){
          v.push_back(r);
          find(j+1,v,s);
           v.pop_back();
        }
         
    }


}
    vector<vector<string>> partition(string s) {
        vector<string> v;
        find(0,v,s);
        return ans;
    }
};