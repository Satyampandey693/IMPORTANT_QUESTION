class Solution {
public:
    bool isValid(string word) {
    int con=0;
    int ch=0;
    bool v=false;
    for(int i=0;i<word.size();i++){
          ch++;
        if(word[i]>='0'&&word[i]<='9'){
            
            continue;
        }
        else if(!(word[i]>='a'&&word[i]<='z'||word[i]>='A'&&word[i]<='Z')) return false;
        word[i]=tolower(word[i]);
      
        if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u') v=true;
        else con++;
    }
    if(!v) return false;
    if(con==0) return false;
    if(ch<3) return false;
    return true;
    }
};