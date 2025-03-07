class Solution {
public:
vector<bool> pr;
void prime(){
    pr[1]=false;

    for(int i=2;i*i<=1e6;i++){
        for(int j=i*i;j<=1e6;j+=i){
            pr[j]=false;
        }
    }
}
    vector<int> closestPrimes(int left, int right) {
        pr.resize(1e6+1,true);
        prime();
        int prev=-1;
        int a=INT_MAX,b=INT_MAX;
        int ans=INT_MAX;
        for(int i=left;i<=right;i++){
            if(pr[i]){
                if(prev!=-1){
                    int p=i-prev;
                    if(ans>p){
                        a=prev;
                        b=i;
                        ans=p;
                    }
                }
                prev=i;
            }
        }
        if(a==INT_MAX) a=-1;
        if(b==INT_MAX) b=-1;
        return {a,b};
    }
};