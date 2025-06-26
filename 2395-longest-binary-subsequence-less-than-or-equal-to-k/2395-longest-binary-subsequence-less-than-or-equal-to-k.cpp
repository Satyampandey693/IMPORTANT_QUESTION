class Solution {
public:
int pow(int a,int b){
    if(b==0) return 1;
    int pr=1;
    while(b){
      if(b&1){
        pr=pr*a;
        b--;
      }
      else{
            a=a*a;
            b/=2;
      }
    }
    return pr;
}
    int longestSubsequence(string s, int k) {
    //    int c=__builtin_popcount(k);
    //    return c; 
    int sz=0;
    bool pr=false;
    long long p=0;
    int ind=0;
    int c=0;
    // cout<<s.size();
    // cout<<pow(2,32);
    for(int i=s.size()-1;i>=0;i--){
        // if(k&1){
        //     if(s[i]=='0'){
        //          sz++;
        //          k=k>>1;
        //          c--;
        //     }
        //     else{
        //       if(pr){
        //         if(c>1){
        //             sz++;
        //             k=k>>1;
        //             c--;

        //         }
        //         else{
        //             c=0;
                    
        //         }
        //       }
        //     }
        // }
        if(s[i]=='0'){
            sz++;
            c++;
        }
        else{
            // cout<<"j";
            if(ind<=30){
                 p+=pow(2,ind);
                  if(p<=k)sz++;
            }
           

           
        }
        ind++;

    }
    // cout<<c<<endl;
    return sz++;

    }
};