class Solution {
public:
vector<string> ans;
void find(int i,int n,string &p){
    if(i==n){
        ans.push_back(p);
        return ;
    }
    if(i!=0){
        char r='a';
        for(;r<='c';r++){
            if(p[i-1]!=r){
                p.push_back(r);
                find(i+1,n,p);
                p.pop_back();
            }
        }
    }
    else{
       char r='a';
        for(;r<='c';r++){
           
                p.push_back(r);
                find(i+1,n,p);
                p.pop_back();
            
        } 
    }
}
    string getHappyString(int n, int k) {
        string p;

       find(0,n,p); 
       if(k>ans.size()) return "";
       sort(ans.begin(),ans.end());
       return ans[k-1];
    }
};