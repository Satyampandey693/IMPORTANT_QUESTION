class Solution {
public:
    bool doesAliceWin(string s) {
        int v=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                v++;
}
        }
        if(v==0) return false;
        if(v&1) return true;
        return true;
        
        
    }
};