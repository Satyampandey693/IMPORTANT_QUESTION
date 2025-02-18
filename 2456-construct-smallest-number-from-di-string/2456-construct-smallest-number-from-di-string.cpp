class Solution {
public:
string ans;
string p;
vector<int> v;
void find(int  j,string &pattern){
    if(j>pattern.size()){
        // cout<<i;
                if(ans.size()>0)
        ans=min(ans,p);
        else ans=p;
        return ;
    }
    if(j==0){
        for(int i=1;i<=9;i++){
            if(!v[i]){
                v[i]++;
                char c=i+'0';
                p.push_back(c);
                find(j+1,pattern);
                p.pop_back();
                v[i]--;
            }
        }
    }
    else{
       for(int i=1;i<=9;i++){
            if(!v[i]){
                if(pattern[j-1]=='D'){
                    char c=i+'0';
                    if(c<p.back()){
                         v[i]++;
                p.push_back(i+'0');
                find(j+1,pattern);
                p.pop_back();
                v[i]--;     
                    }

                }
                else{
                      char c=i+'0';
                    if(c>p.back()){
                         v[i]++;
                p.push_back(i+'0');
                find(j+1,pattern);
                p.pop_back();
                v[i]--;     
                    }
                }
                
            }
        } 
    }

}
    string smallestNumber(string pattern) {
        v.resize(10,0);
        find(0,pattern);
        return ans;
    }
};