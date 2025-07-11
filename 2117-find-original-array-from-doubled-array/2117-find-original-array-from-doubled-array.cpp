class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()&1) return {};
        sort(changed.begin(),changed.end());
        map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<changed.size();i++){
            if(mp.find(changed[i])!=mp.end()){
                 ans.push_back(changed[i]/2);
                 mp[changed[i]]--;
                 if(mp[changed[i]]==0) mp.erase(changed[i]);
            }
            else{
                mp[changed[i]*2]++;
            }
        }
        if(ans.size()<changed.size()/2) return {};
        return ans;
    }
};