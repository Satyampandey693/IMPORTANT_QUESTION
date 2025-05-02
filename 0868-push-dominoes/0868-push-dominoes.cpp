class Solution {
public:
    string pushDominoes(string d) {
        int i=0;
        int j=0;
        int n=d.size();
        string ans=d;
        while(i<n){
            // cout<<j<<" "<<i<<endl;
            while(i<n&&d[i]=='.') i++;
            if(d[j]=='.'&&i<n){
                
                while(j<i&&d[i]=='L'){
                 ans[j]=d[i]; 
                 j++;
                 }
            }
            else if(i==n){
                if(d[j]=='L') continue;
                char p=d[j];
                j++;
                 while(j<i){
                 ans[j]=p; 
                 j++;}
            }
            else if(i<n&&(d[i]=='L'&&d[j]=='L')||(d[i]=='R'&&d[j]=='R')){
                 char p=d[j];
                 j++;
                 while(j<i){
                 ans[j]=p; 
                 j++;}
            }
            else if(!(d[i]=='R'&&d[j]=='L')){
                // cout<<"I";
                 int r=j+i;
                int q=r/2;
                if(r&1){
                     char p=d[j];
                 j++;
                     while(j<i){
                        if(j<=q)
                       ans[j]=p; 
                       else
                       ans[j]=d[i];
                        j++;}
                }
                else{
                    // cout<<"s";
                      char p=d[j];
                 j++;
                     while(j<i){
                        if(j<q)
                       ans[j]=p; 
                       else if(j>q)
                       ans[j]=d[i];
                        j++;}
                }
            }
            while(i<n&&d[i]!='.') i++;
            if(i<n&&d[i]=='.'){
                j=i-1;
            }

        }
        return ans;
    }
};