class Solution {
public:
    int maximumGain(string s, int x, int y) {
        //ba priority
        // stack<char> st;
        int a=0;
        int b=0;
        int ans=0;
        int p=0;  
        for(int i=0;i<s.size();i++){
          if(s[i]=='a'){
            if(b){
                p+=y;
                b--;
            }
            else
            a++;

          }
          else if(s[i]=='b') b++;
          else{
             p+=x*min(a,b);
             a=0,b=0;
          }
        //  cout<<a<<" "<<b<<endl;
        }
        // cout<<p;
        //ab
         p+=x*min(a,b);
        ans=max(ans,p);
        a=0;
        b=0;
         p=0;
        for(int i=0;i<s.size();i++){
          if(s[i]=='a'){
           
            a++;

          }

          else if(s[i]=='b') {
             if(a){
                p+=x;
                a--;
            }
            else b++;
           }
          else{
             p+=y*min(a,b);
             a=0,b=0;
          }
        }
        // cout<<a<<" "<<b;
 p+=y*min(a,b);
return max(p,ans);

    }
};