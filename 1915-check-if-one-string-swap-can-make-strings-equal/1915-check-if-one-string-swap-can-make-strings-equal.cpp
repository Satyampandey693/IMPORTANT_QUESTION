class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff=0;
        int ind1=-1,ind2=-1;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
              diff++;
              if(ind1==-1)ind1=i;
              else  if(ind2==-1) ind2=i;
            }
        }
        if(diff>2||diff==1) return false;
        if(diff==0) return true;
        if((s1[ind1]==s2[ind2]&&(s1[ind2]==s2[ind1]))) return true;
        return false;
    }
};