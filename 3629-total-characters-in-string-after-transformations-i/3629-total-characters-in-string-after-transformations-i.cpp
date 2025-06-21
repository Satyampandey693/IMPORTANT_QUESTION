class Solution {
public:
int mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<long long> v(26,0);
       for(int i=0;i<s.size();i++){
          v[s[i]-'a']++;
       }

       for(int i=1;i<=t;i++){
        vector<long long> nv(26,0);
          for(int j=0;j<26;j++){
                if(j==0){
                    nv[j]=v[25];
                }
                else if(j==1){
                    nv[j]=(v[25]+v[j-1])%mod;
                }
                else {
                    nv[j]=v[j-1];
                }
          }
          v=nv;
       }
       int ans=0;
       for(int i=0;i<26;i++){
        ans=(ans+v[i])%mod;
       }
       return ans;
    }
};