class Solution {
public:
vector<vector<string>> ans;
vector<string> temp;
string r;
void create(int n){
    // string p;
    for(int i=0;i<n;i++){
     r.push_back('.');
    }
    temp.resize(n,r);

}

map<int,bool> col;
map<int,bool> rt;
map<int,bool> lf;
void find(int i,int &n){
    if(i==n){
       
        ans.push_back(temp);
        return;
    }

    for(int j=0;j<n;j++){
        if(col[j]||rt[n-1+j-i]||lf[(i+j)]) continue;
        col[j]=true;
        rt[n-1+j-i]=true;
        lf[abs(i+j)]=true;
        temp[i][j]='Q';
        // temp.push_back(r);
        col[j]=true;
        find(i+1,n);
        col.erase(j);
        rt.erase(n-1+j-i);
        lf.erase(abs(i+j));
        temp[i][j]='.';
        // temp.pop_back();

    }
}


    vector<vector<string>> solveNQueens(int n) {
        create(n);
        find(0,n);
        return ans;

    }
};