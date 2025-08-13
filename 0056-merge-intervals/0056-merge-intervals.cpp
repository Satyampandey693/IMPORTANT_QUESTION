class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }
            int a=ans.back()[0];
            int b=ans.back()[1];
            ans.pop_back();
            if(b>=intervals[i][0]){
                a=min(a,intervals[i][0]);
                b=max(b,intervals[i][1]);
                ans.push_back({a,b});
            }
            else{
                ans.push_back({a,b});
                ans.push_back(intervals[i]);
            }
        }
        return ans;

    }
};