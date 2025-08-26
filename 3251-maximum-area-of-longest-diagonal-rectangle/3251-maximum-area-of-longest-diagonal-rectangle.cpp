class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int idx=0;
        int l=0;
        int ans=0;
        for(int i=0;i<dimensions.size();i++){
            int p=dimensions[i][0];
            int q=dimensions[i][1];
            int r=p*p+q*q;
            if(r>l){
                l=r;
                idx=i;
                   int na=dimensions[i][0]*dimensions[i][1];
                ans=na;
            }
            if(r==l){
                int na=dimensions[i][0]*dimensions[i][1];
                ans=max(ans,na);
            }
        }
        return ans;
    }
};