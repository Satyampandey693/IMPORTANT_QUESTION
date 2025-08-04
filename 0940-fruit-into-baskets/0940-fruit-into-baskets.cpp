class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       map<int,int> mp;
       int i=0;
       int j=0;
       int ans=0;
       while(i<fruits.size()){
        mp[fruits[i]]++;
        while(mp.size()>2){
            mp[fruits[j]]--;
            if( mp[fruits[j]]==0) mp.erase(fruits[j]);
            j++;
        }
        ans=max(ans,i-j+1);
        i++;
       } 
       return ans;
    }
};