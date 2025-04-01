class Solution {
public:
vector<long long> dp;
long long find(int i,vector<vector<int>>& questions){
    if(i>=questions.size()){
        return 0;
    }
    if(dp[i]!=-1) return dp[i];
    long long ns,s;
    //not select;
    ns=find(i+1,questions);
    //select
    s=questions[i][0]+find(i+questions[i][1]+1,questions);
    return dp[i]= max(ns,s);
}
    long long mostPoints(vector<vector<int>>& questions) {
        dp.resize(1e5+1,-1);
        return find(0,questions);
    }
};