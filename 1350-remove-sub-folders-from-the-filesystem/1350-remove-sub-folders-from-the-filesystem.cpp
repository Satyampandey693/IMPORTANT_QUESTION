class Solution {
public:
bool check(string &a,string &b){
    if(a.size()>b.size()) return false;
    int i=0;
    int j=0;
    while(i<a.size()&&j<b.size()){
        if(a[i]!=b[j]) return false;
        i++;
        j++;
    }
    if(j<b.size()){
        return b[j]=='/';
    }
    return true;
}
    vector<string> removeSubfolders(vector<string>& folder) {
      vector<string> ans;
      int n=folder.size();
      sort(folder.begin(),folder.end());
      int i=0;

      while(i<n){
        ans.push_back(folder[i]);
        int j=i+1;
        while(j<n){
            if(!check(folder[i],folder[j])){
                break;
            }
            j++;
        }
        i=j;
      }
      return ans;

    }
};