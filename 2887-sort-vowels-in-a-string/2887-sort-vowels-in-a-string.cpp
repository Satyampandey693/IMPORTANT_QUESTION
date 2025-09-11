class Solution {
public:
    string sortVowels(string s) {
        map<char,int> m;
        for(int i=0;i<s.length();i++){
            if(tolower(s[i])=='a'||tolower(s[i])=='e'||tolower(s[i])=='i'||tolower(s[i])=='o'||tolower(s[i])=='u')m[s[i]]++;
        }
        // cout<<m.size();
        // for(auto i:m){
        //     cout<<i.first;
        // }
        string ans;
        int i=0;
        while(i<s.length()){
            if(tolower(s[i])!='a'&&tolower(s[i])!='e'&&tolower(s[i])!='i'&&tolower(s[i])!='o'&&tolower(s[i])!='u'){
                ans+=s[i];
                // cout<<i;
            }
            else{
                // cout<<"a";
                // cout<<m.begin()->first;
                
                ans+=m.begin()->first;
                m.begin()->second--;
                if( m.begin()->second==0) m.erase(m.begin()->first);
            }
            i++;
        }
        return ans;
        
    }
};