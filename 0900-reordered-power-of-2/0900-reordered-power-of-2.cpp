class Solution {
public:
bool check(int n,int p){
    // vector<int> dig1;
    // vector<int> dig2;
    string s1=to_string(n);
    string s2=to_string(p);
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
return s1==s2;


}
    bool reorderedPowerOf2(int n) {
        for(int i=0;i<31;i++){
            int p=1<<i;
            if(check(n,p))return true;

        }
       return false; 
    }
};