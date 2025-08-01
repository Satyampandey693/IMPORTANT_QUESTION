class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> p;
            vector<int> pr=ans.back();
            p.push_back(1);
            for(int j=1;j<pr.size();j++){
               p.push_back(pr[j]+pr[j-1]);
            }
            p.push_back(1);
            ans.push_back(p);
        }
        return ans;
    }
};