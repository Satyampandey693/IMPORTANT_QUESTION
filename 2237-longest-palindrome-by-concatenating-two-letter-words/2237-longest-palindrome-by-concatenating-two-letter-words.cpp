class Solution {
public:
    int longestPalindrome(vector<string>& words) {
         map<string,int> mp;
         for(int i=0;i<words.size();i++){
            mp[words[i]]++;
            // cout<<i;
         }
         int r=0;
         int ans=0;
         for(int j=0;j<words.size();j++){
            // cout<<words[j]<<" "<<mp[words[j]]<<endl;
             if((words[j][0]==words[j][1])&&(mp.find(words[j])!=mp.end())){
                // cout<<"K";
                ans+=mp[words[j]];
                 if(mp[words[j]]&1){ 
                r++;
                ans--;
                }
                mp.erase(words[j]);
               
             }
             else if((words[j][0]!=words[j][1])&&(mp.find(words[j])!=mp.end())){
                string p = words[j];
                reverse(p.begin(), p.end());

                int q=min(mp[words[j]],mp[p]);
                ans+=q*2;
                 mp.erase(words[j]);
                  mp.erase(p);

             }

         }
        //  cout<<ans;
         if(r) ans++;
         return  ans*2;
    }
};