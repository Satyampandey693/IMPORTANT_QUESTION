class Solution {
public:
    string largestGoodInteger(string num) {
        int c=1;
        string ans;
        for(int i=1;i<num.size();i++){
            if(num[i]==num[i-1])c++;
            else{
                c=1;
            }
            if(c==3){
                string p=num.substr(i-2,3);
                if(ans.empty()) ans=p;
                else ans=max(ans,p);
            }
        }
        return ans;
    }
};