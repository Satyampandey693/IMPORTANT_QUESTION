class Solution {
public:
    int minMaxDifference(int num) {
        int c1=-1,c2=-1;
        int p=num;

        while(p){
           int mod=p%10;
        if(mod!=0&&mod)
        { 
            c2=mod;
        }
        if(mod!=9&&c1==-1){

        }
        p/=10;
        }

    //    int mini=0;
    //    int i=0;
    //    p=num;
    //    while(p){

    //    }
    string s=to_string(num);
   int mf=-1;
    for(int i=0;i<s.size();i++){
        if((s[i]-'0'!=9)&&mf==-1){
           mf=s[i]-'0';
        }
        if(mf!=-1&&s[i]-'0'==mf){
            s[i]='9';
        }
    }
    int mx=stoi(s);
    s=to_string(num);
    mf=-1;
    for(int i=0;i<s.size();i++){
        if(mf==-1){
           mf=s[i]-'0';
        }
        if(s[i]-'0'==mf){
            s[i]='0';
        }
    }
    // cout<<mx;
    int mn=stoi(s);
    return mx-mn;

    }
};