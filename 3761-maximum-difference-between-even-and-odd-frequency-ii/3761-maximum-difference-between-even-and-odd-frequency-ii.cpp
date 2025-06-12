class Solution {
public:
   int getStatus(int cnt_a, int cnt_b) {
        return ((cnt_a & 1) << 1) | (cnt_b & 1);
    }
    int maxDifference(string s, int k) {
        int n=s.size();
        int ans=INT_MIN;
        for(int i=0;i<5;i++){
            for(char j=0;j<5;j++){
                if(i==j) continue;
                // if(i!=0||j!=1) continue;
                // int f=0;
                // int s=0;
                vector<int> f(n+1,0);
                vector<int> se(n+1,0);
                // int par[2][2]={{INT_MAX,}}
                vector<int> par={INT_MAX,INT_MAX,INT_MAX,INT_MAX};
                 for (int k = 1; k <= n; ++k) 
                {
                    f[k] = f[k - 1] + (s[k - 1] - '0' == i);
                    se[k] = se[k - 1] + (s[k - 1] - '0' == j);
                }
                int p=0,q=1;
                while(q<=n){
                    //se[q]-se[p]>=2 this condition is for that second char freq in this range at least 2
                    // because 0 also be considered as even but 0 freq is not considered here as even in this q 

                    while(q-p>=k && se[q]-se[p]>=1){
                    int r=getStatus(f[p],se[p]);
                    par[r]=min(par[r],f[p]-se[p]);
                    p++;
                    }
                     int right_status = getStatus(f[q],se[q]);
                    int t = right_status ^ 2;
                if(par[t]!=INT_MAX){
                    ans=max(ans,(f[q]-se[q]-par[t]));
                }
                q++;
                }
                // cout<<endl;

            }
        }
        return ans;
    }
};