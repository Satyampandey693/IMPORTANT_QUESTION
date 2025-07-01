class Solution {
public:
    int possibleStringCount(string word) {
        vector<int> v(26,0);
        // for(int i=0;i<word.size();i++){
        //     v[word[i]-'a']++;
        // }
        // int ans=0;
        // for(int i=0;i<26;i++){
        //     if(v[i]>1)
        //     ans+=v[i]-1;
        // }
        // return ans+1;
    int c=1;
    int ans=0;
    for(int i=1;i<word.size();i++){
      if(word[i]==word[i-1])c++;
      else{
        ans+=c-1;
        c=1;
      }
    }
    if(c!=1)ans+=c-1;
    return ans+1;
    }
};