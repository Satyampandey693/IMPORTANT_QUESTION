class Solution {
public:
    string answerString(string word, int numFriends) {
        // vector<int> v(26,-1);
        if(numFriends==1) return word;
        // for(int i=0;i<word.size();i++){
        //     char c=word[i]-'a';
        //     if(v[c]==-1){
        //         v[c]=i;
        //     }
        // }

    //   int ind=-1;
      char p= *max_element(word.begin(), word.end());;
    //   for(int i=25;i>=0;i--){
    //     if(v[i]!=-1&&ind==-1) ind=v[i];
    //   }
    //   p=word[ind];
      numFriends--;
    int l=word.size()-numFriends;
    
    string ans;
    for(int i=0;i<word.size();i++){
        if(word[i]==p){
        string q=word.substr(i,l);
            // if(ans<q) ans=q;
            ans=max(ans,q);
        }
    }
      return ans;
    }
};