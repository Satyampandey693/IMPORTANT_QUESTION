class Solution {
public:
    int maxDistance(string s, int k) {
        int px=0,py=0,nx=0,ny=0;
        int ans=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(s[i]=='E') px++;
            else if(s[i]=='W') nx++;
            else if(s[i]=='N') py++;
            else ny++;
            int p=k;
            int mx=max(px,nx);
            int mn=min(px,nx);
            int r=min(mn,p);
            mx+=2*r;
            // mx+=r;
            // mn-=r;
            p-=r;
            int my=max(py,ny);
            int mny=min(py,ny);
            int ry=min(mny,p);
            // mny-=ry;
            // my+=
            // cout<<r<<" "<<ry;
            p-=ry;
            my+=2*ry;
            int md=mx-mn+my-mny;
            ans=max(ans,md);
            // cout<<ans<<endl;
        }
        return ans;
    }
};