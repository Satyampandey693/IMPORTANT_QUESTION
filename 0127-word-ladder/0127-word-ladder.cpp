class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int> mp;
        for(int i=0;i<wordList.size();i++){
            mp[wordList[i]]++;
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        map<string,int> b;
        b[beginWord]++;
        while(!q.empty()){
           string p=q.front().first;
           int c=q.front().second;
           q.pop();
            string r=p;
            if(r==endWord) return c;
           for(int j=0;j<p.size();j++){
              for(int i=0;i<26;i++){
               if(p[j]==i+'a') continue;
                 char t=r[j];
                 r[j]=i+'a';
                
                 if(b.find(r)==b.end()&&(mp.find(r)!=mp.end())){
                    b[r]++;
                    q.push({r,c+1});
                 }
                 r[j]=t;
           }
           }
           

        }
        return 0;
    }
};