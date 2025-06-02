class Solution {
public:
    int candy(vector<int>& ratings) {
        // return 0;
        int n=ratings.size();
        if(n==1) return 1;
        vector<int> ans(ratings.size(),1);
        for(int i=0;i<ratings.size();i++){
            // if(i==0){
            //     if(ratings[i]>ratings[i+1])
            // }
            if(i+1<n&&ratings[i]>ratings[i+1]){
                ans[i]=ans[i+1]+1;
            }
            if(i>0&&ratings[i]>ratings[i-1]){
                ans[i]=ans[i-1]+1;
            }
        }
        
        for(int i=ratings.size()-1;i>=0;i--){
            // if(i==0){
            //     if(ratings[i]>ratings[i+1])
            // }
            if(i+1<n&&ratings[i]>ratings[i+1]){
                ans[i]=max(ans[i+1]+1,ans[i]);
            }
            if(i>0&&ratings[i]>ratings[i-1]){
                ans[i]=max(ans[i],ans[i-1]+1);
            }
        }
        int c=0;
        for(int i=0;i<n;i++)c+=ans[i];
        return c;
    }
};