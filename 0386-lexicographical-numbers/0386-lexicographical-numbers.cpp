class Solution {
public:
vector<int>ans;
void find(int i,int n){
    if(i>n) return ;
    for(int j=0;j<=9;j++){
     int p=i*10+j;
     if(p==0) continue;
     if(p<=n) ans.push_back(p);
     find(p,n);
    }
}
    vector<int> lexicalOrder(int n) {
        find(0,n);
        return ans;
    }
};