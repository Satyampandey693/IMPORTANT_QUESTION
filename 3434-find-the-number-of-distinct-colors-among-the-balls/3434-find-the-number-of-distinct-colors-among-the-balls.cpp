class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> mb;
       unordered_map<int,int> mc;
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int b=queries[i][0];
            int c=queries[i][1];
            if(mb.find(b)!=mb.end()){
                mc[mb[b]]--;
                if(mc[mb[b]]==0)mc.erase(mb[b]);
            }
            mc[c]++;
            mb[b]=c;
            ans.push_back(mc.size());

        }
        return ans;
    }
};