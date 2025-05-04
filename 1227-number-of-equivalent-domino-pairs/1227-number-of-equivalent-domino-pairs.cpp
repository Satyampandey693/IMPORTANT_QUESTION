class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int> mp;
        int ans=0;
        for(int i=0;i<dominoes.size();i++){
            int p=min(dominoes[i][0],dominoes[i][1]);
              int q=max(dominoes[i][0],dominoes[i][1]);
              ans+=mp[{p,q}]++;
        }
        return ans;

    }
};