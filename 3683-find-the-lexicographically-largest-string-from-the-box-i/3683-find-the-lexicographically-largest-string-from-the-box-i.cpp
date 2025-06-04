class Solution {
public:
    string answerString(string word, int numFriends) {
        vector<int> v(26,-1);
        if(numFriends==1) return word;
        for(int i=0;i<word.size();i++){
            char c=word[i]-'a';
            if(v[c]==-1){
                v[c]=i;
            }
        }

      int ind=-1;
      char p;
      for(int i=25;i>=0;i--){
        if(v[i]!=-1&&ind==-1) ind=v[i];
      }
      p=word[ind];
    //   int l1=ind;
    //   cout<<l1<<endl;
      numFriends--;
    //   if(l1>num)
    //   numFriends-=l1;
    int l=word.size()-numFriends;
      
    //   numFriends=max(0,numFriends);
    //   int l2=word.size()-ind;
      
    //   l2-=numFriends;
    //   cout<<l2<<endl;
    string ans;
    for(int i=0;i<word.size();i++){
        if(word[i]==p){
        string q=word.substr(i,l);
            if(ans<q) ans=q;
        }
    }
    //   string ans=word.substr(ind,l2);
      return ans;
    }
};