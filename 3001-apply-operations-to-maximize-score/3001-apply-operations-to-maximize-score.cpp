class Solution {
public:
#define  ll long long
   vector<int> prime;
   int mod=1e9+7;
   void checkPrime(){
     prime.resize(1e5+1,1);
     for(int i=2;i<=1e5;i++){
      prime[i]=i;
     }
    
    for(int i=2;i*i<=1e5;i++){
        if(prime[i]!=i)continue;
        for(int j=i*i;j<=1e5;j+=i){
            prime[j]=i;
        }

    }

   }
   int noOfP(int n){
   
    int p=0;
    set<int> st;
   while(prime[n]!=1){
     int r=n/prime[n];
      st.insert(prime[n]);
      n=r;
     
   }

   return st.size();
   }
   int exponen(ll n,ll m){
    ll a=1;
    while(m){
     if(m&1){
        a=(a*1ll*n)%mod;
        m--;
     }
     else{
        n=(n*n)%mod;
        m/=2;
     }
    }
    return a;
   }
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
       vector<int> pr(n);
       checkPrime();
       priority_queue<pair<int,int>> pq;

       for(int i=0;i<nums.size();i++){
        int np=noOfP(nums[i]);
        pr[i]=np;
        // cout<<pr[i]<<" ";
        pq.push({nums[i],i});
       }
       vector<int> leftgr(n);
       vector<int> rightgr(n);
       int i=n-1;
       stack<int> st;
       while(i>=0){
             while(!st.empty()&&pr[st.top()]<=pr[i]){
                st.pop();
             }
             if(!st.empty())
             rightgr[i]=st.top()-i;
             else rightgr[i]=n-i;
             
             st.push(i);

             i--;
       }
       while(!st.empty()){
        st.pop();
       }
       i=0;
       while(i<n){
        while(!st.empty()&&pr[st.top()]<pr[i]){
                st.pop();
             }
             if(!st.empty())
             leftgr[i]=i-st.top();
             else leftgr[i]=i+1;


             
             st.push(i);
             i++;
       }
   
       ll ans=1;
       ll nk=k;
       while(nk){
        int ind=pq.top().second;
        int p=pq.top().first;
        pq.pop();
        ll t=0;
        t=leftgr[ind]*1ll*rightgr[ind];
               int mn=min(nk,t);
        ans=(ans*exponen(p,mn))%mod;
        nk-=mn;
       }
       return ans;
    }
};