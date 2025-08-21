class Solution {
public:
int find(vector<int> &p){
    int n=p.size();
//     vector<int> lss(n,n);
//     int mn=INT_MAX;
//    int i=n-1;
//     stack<int> st;
//    while(i>=0){
//     while(!st.empty()&&p[st.top()]>p[i]) st.pop();
//     if(!st.empty()) lss[i]=st.top();
//     st.push(i);
//     mn=min(mn,p[i]);
//     i--;
//    }
//    vector<int> rss(n,-1);
//    i=0;

//   while(!st.empty()) st.pop();
// while(i<n){
//     while(!st.empty()&&p[st.top()]>p[i]) st.pop();
//     if(!st.empty()) rss[i]=st.top();
//     st.push(i);
//     // mn=min(mn,p[i]);
//     i++;
//    }
   int t=0;
for(int i=0;i<n;i++){
    // if(p[i]!=0)
    // t+=(lss[i]-rss[i])-1 +p[i]-1;
    // cout<<lss[i]<<" "<<rss[i]<<"nx";
    int mn=p[i];
    for(int j=i;j<n;j++){
        // if()
        // if(p[j]==0) break;
        // mn

        t+=min(p[j],mn);
        mn=min(mn,p[j]);
    }

}
// cout<<mn<<" ";;
// for(int i=mn-1;i>0;i--){
//     t+=n*(n+1)/2;
// }
// cout<<t<<endl;
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