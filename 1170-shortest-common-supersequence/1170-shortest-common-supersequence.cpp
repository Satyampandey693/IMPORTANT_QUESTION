class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
         vector<vector<int>> dp( text1.size()+1,vector<int>( text2.size()+1,0));
        // vector<int> prev(text2.size(),0);
        // return find(text1,text2,0,0,dp);
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++)
            {
                if(text1[i-1]==text2[j-1]){
                        dp[i][j]=1;
                        if(i>0&&j>0) dp[i][j]+=dp[i-1][j-1];
                }
                else {
                    int p=0;
                    if(i>0)
                    p=dp[i-1][j];
                    int q=0;
                    if(j>0)
                    q=dp[i][j-1];
                    dp[i][j]=max(p,q);

                }
            }
        }
       
        // for(int i=0;i<text1.size();i++){
        //     vector<int>  dp(text2.size(),0);
        //     for(int j=0;j<text2.size();j++){
        //         if(text1[i]==text2[j]) {dp[j]=1;
        //         if(i>0&&j>0){
        //            dp[j]=1+prev[j-1];
        //         }

        //         }
        //         else{
        //             if(i>0) dp[j]=prev[j];
        //             if(j>0) dp[j]=max(dp[j-1],dp[j]);
        //             // dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        //         }
        //     }
        //     prev=dp;
        // }
        // return prev[text2.size()-1];
        int i=text1.size();
        int  j=text2.size();
        string ans;
        while(i>0&&j>0){
            if(text1[i-1]==text2[j-1]){
                ans.push_back(text2[j-1]);
                i--;
                j--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j]){
                    ans.push_back(text2[j-1]);
                   j--;
                }
                else {
                    ans.push_back(text1[i-1]);
                    i--;}
            }
        }
        while(i>0){ans.push_back(text1[i-1]);i--;}
        while(j>0){ans.push_back(text2[j-1]);j--;}

// cout<<ans;
//  return dp[text1.size()][text2.size()];
 reverse(ans.begin(),ans.end());
return ans;
    }
};