class Solution {
public:
#define ll long long
int mod=1e9+7;
ll pow(ll n,  ll p) {
    if (p == 0) return 1;
    ll ans = 1;
    while (p) {
        if (p & 1) {
            ans = (ans * n)%mod;
            p--;
        } else {
            n =( n * n)%mod;
            p = p / 2;
        }
    }
    return ans;
}
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
       vector<int> arr;
       while(n){
        int p=log2(n);
        int r=(1<<p);
        n=n-r;
        arr.push_back(r);
       }
       vector<int> ans;
       
       sort(arr.begin(),arr.end());
       cout<<arr[0]<<" ";
       for(int i=1;i<arr.size();i++){
        // cout<<arr[i]<<" ";
        int p=(arr[i-1]*1ll*arr[i])%mod;
        arr[i]=p;
        cout<<arr[i]<<" ";
       }
       for(int i=0;i<queries.size();i++){
        int a=queries[i][1];
        int b=queries[i][0];
        int p=arr[a];
       
        int q=1;
         if(b>0)
         q=arr[b-1];
              p=(p*pow(q,mod-2))%mod;
             ans.push_back(p);
                    }
                    return ans;
    }
};