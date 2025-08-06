class Solution {
public:
string arr[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string> ans;
void find(int i,string &v,string &s){
   
    if(i>=s.size())  {
        if(!v.empty())
        ans.push_back(v);
        return ;
    }
   
   int p=s[i]-'2';
   string r=arr[p];
    for(int j=0;j<r.size();j++){
       
        v.push_back(r[j]);
        find(i+1,v,s);
        v.pop_back();
         
    }


}
    vector<string> letterCombinations(string digits) {
        // map<int,char<int>> mp;
        string v;

    find(0,v,digits);
    return ans;
    }
};