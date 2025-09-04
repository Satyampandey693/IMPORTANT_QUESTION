class Solution {
public:
int find(vector<int> &p){
    int n=p.size();
    vector<int> lss(n,n);
    int mn=INT_MAX;
   int i=n-1;
    stack<int> st;
   while(i>=0){
    while(!st.empty()&&p[st.top()]>=p[i]) st.pop();
    if(!st.empty()) lss[i]=st.top();
    
    st.push(i);
    mn=min(mn,p[i]);
    i--;
   }

   int t=0;
   vector<int> tot(n,0);
for(int i=n-1;i>=0;i--){
    int q=0;
    int nx=lss[i];
    q+=(nx-i)*p[i];
    if(nx<n) q+=tot[nx];
    tot[i]=q;
t+=q;
    

}
return t;

}
    int numSubmat(vector<vector<int>>& mat) {
        int ans=0;
        for(int i=0;i<mat.size();i++){
            if(i!=0){
                for(int j=0;j<mat[0].size();j++){
                    if(mat[i][j]!=0) mat[i][j]+=mat[i-1][j];
                }
            }
            vector<int> p=mat[i];
           ans+= find(p);
              
        }
        return ans;
    }
};