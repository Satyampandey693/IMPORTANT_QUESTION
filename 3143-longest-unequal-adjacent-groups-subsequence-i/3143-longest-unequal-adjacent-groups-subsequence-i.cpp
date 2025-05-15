class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
         int prev;
        vector<string> ans;
         vector<string> t2;
        vector<string> t;
        if(groups[0]==1){
            t.push_back(words[0]);
            prev=1;
        for(int i=1;i<n;i++){
            if(groups[i]!=prev){
                t.push_back(words[i]);
                prev=groups[i];
            }

        }
        }
        else{
           
           t2.push_back(words[0]);
            prev=0;
        for(int i=1;i<n;i++){
            if(groups[i]!=prev){
                t2.push_back(words[i]);
                prev=groups[i];
            }

        } 
        }
        if(t.size()>t2.size()) ans=t;
        else ans=t2;
        return ans;
    }
};