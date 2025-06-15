class Solution {
public:
    int maxDiff(int num) {
        string a=to_string(num);
        string b=to_string(num);
        int f=-1;
        for(int i=0;i<a.size();i++){
            if(a[i]!='9'&&f==-1) {
             f=a[i]-'0';
            }
            if(f!=-1&&(a[i]-'0'==f)){
                  a[i]='9';
            }
        }
        int mx=stoi(a);
         f=-1;
         if(b[0]!='1'){f=b[0]-'0';
         b[0]='1';
         }
         if(f!=-1){
            for(int i=0;i<b.size();i++){
                if(b[i]==f+'0'){
                    b[i]='1';
                }
            }
         }
          else{
        for(int i=1;i<a.size();i++){
             if(b[i]!='0'&&f==-1) {
                if(b[i]==b[0])continue;
             f=b[i]-'0';
            }
            if(f!=-1&&(b[i]-'0'==f)){
                  b[i]='0';
            }
        }
          }
       
    // cout<<mx;
        int mn=stoi(b);
        return mx-mn;
    }
};