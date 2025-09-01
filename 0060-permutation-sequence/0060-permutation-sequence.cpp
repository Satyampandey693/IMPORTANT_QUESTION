class Solution {
public:
int p=0;
string ans;
void find(int i,int n,int k,string &arr,vector<int> &vis){
    if(i==n){
      p++;
      if(p==k) ans=arr;
      return ;
    }
    if(!ans.empty()) return ;
    for(int j=1;j<=n;j++){
        if(vis[j]) continue;
        arr.push_back(j+'0');
        vis[j]++;
        find(i+1,n,k,arr,vis);
        if(!ans.empty()) return ;
        vis[j]--;
        arr.pop_back();
    }

}
    string getPermutation(int n, int k) {
        // string p;
       string arr;
       vector<int> vis(n+1);
        find(0,n,k,arr,vis);
        return ans;
    }
};