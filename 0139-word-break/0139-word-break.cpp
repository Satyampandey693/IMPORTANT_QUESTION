class Solution {
public:
bool find(int i,string s,map<string,int> &mp,vector<int> &dp){
    if(i>=s.size()){
    return true;
    }
    if(dp[i]!=-1) return dp[i];

    string sub;
    for(int j=i;j<s.size();j++){
      sub.push_back(s[j]);
      if(mp.find(sub)!=mp.end()){
        if(find(j+1,s,mp,dp)) return dp[i]= true;
      }
    }
    return dp[i]=false;

}
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string ,int> mp;
        for(int i=0;i<wordDict.size();i++) mp[wordDict[i]]++;
        vector<int> dp(301,-1);
        return find(0,s,mp,dp);
    }
};