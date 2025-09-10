class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int ans=INT_MAX;
        map<int,map<int,int>> mp;
        for(int i=0;i<languages.size();i++){
            for(int j=0;j<languages[i].size();j++){
                mp[i][languages[i][j]]++;

            }
            sort(languages[i].begin(),languages[i].end());
        }
       vector<vector<int>> nfriendships;
        for(int j=0;j<friendships.size();j++){
                int c=0;
                int f1=friendships[j][0];
                int f2=friendships[j][1];
                  
                 vector<int> p=languages[f1-1];
                 vector<int> q=languages[f2-1];
                 int k1=0,k2=0;
                
                 while(k1<p.size()&&k2<q.size()){
                 if(p[k1]==q[k2]) {
                    c++;
                    break;
                 }
                    if(p[k1]<q[k2]){
                        k1++;
                    }
                    else{
                        k2++;
                    }
                 }
                 if(c==0){
                    nfriendships.push_back({f1,f2});
                 }

            }
  

    //  cout<<nfriendships.size()<<endl;
        for(int i=1;i<=n;i++){
             int p=0;
            for(int j=0;j<nfriendships.size();j++){
                int c=0;
                int f1=nfriendships[j][0];
                int f2=nfriendships[j][1];
                  
                    if(mp[f1-1][i]==0) c++;
                    if(mp[f2-1][i]==0) c++;
                    p+=c;
                    mp[f1-1][i]++;
                    mp[f2-1][i]++;

            }
            // cout<<p<<endl;
            ans=min(ans,p);
             for(int j=0;j<nfriendships.size();j++){
                int f1=nfriendships[j][0];
                int f2=nfriendships[j][1];
                    mp[f1-1][i]--;
                    mp[f2-1][i]--;

            }
        }
        return ans;
    }
};