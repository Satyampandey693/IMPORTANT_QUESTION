class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

    int i=0,j=0;
    int ans=0;
    while(i<players.size()){
        while(j<trainers.size()&&trainers[j]<players[i]) j++;
        if(j<trainers.size()&&trainers[j]>=players[i]){
            ans++;
            j++;
        }
        i++;
    }
    return ans;
    }
};