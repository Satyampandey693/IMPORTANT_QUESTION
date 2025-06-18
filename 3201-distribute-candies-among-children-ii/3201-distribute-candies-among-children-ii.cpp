class Solution {
public:
    long long H3(long long n){
        // if(n<0) return 0;
        if(n<=1) return 0;
        return n<0?0:(n)*(n-1)/2;
    }
    long long distributeCandies(int n, int limit) {
        // return H3(n)-3LL*H3(n-limit-1)+3LL*H3(n-2*(limit+1))-H3(n-3*(limit+1));
        // cout<<
       return  H3(n+2)+3*H3(n-2*limit)-3*H3(n-limit+1)-H3(n-3*limit-1);
        // return max(p,(long long)0);
        // long long ans=0;
        // for(int x=0;x<=limit;x++){
        //     int s=n-x;//y+z
        //     if(s>2*limit||s<0) continue;//if y+z>2*l then its not good sol
        //     int ymax=min(s,limit);//when z=0 hoga then x min hoga
        //     int ymin=max(0,s-limit);//when z max value hoga then y min hoga
        //     // cout<<ymax-ymin+1<<endl;
        //     ans+=(ymax-ymin+1);
        // }
        // return ans;
    }
};
