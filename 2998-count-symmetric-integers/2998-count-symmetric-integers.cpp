class Solution {
public:
    bool symmetric(int i){
        int s1=0;
        int s2=0;
        int d=0;
        int p=i;
        while(i){
            d++;
            i=i/10;
        }
        // cout<<p<<" "<<d<<endl;
        i=p;
        if(d&1) return false;
        for(int j=0;j<d/2;j++){
            s1+=i%10;
            i=i/10;
        }
        for(int j=0;j<d/2;j++){
            s2+=i%10;
            i=i/10;
        }
        return s1==s2;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            if(symmetric(i)) ans++;
        }
        return ans;
    }
};