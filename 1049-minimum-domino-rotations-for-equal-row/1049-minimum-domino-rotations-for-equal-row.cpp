class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
       int f=-1,q=-1;
        f=tops[0];
        q=bottoms[0];
       bool y1=true,y2=true;
      
       int t1=0,t2=0;
       int b1=0,b2=0;
       
       for(int i=0;i<tops.size();i++){
        if(tops[i]!=f&&bottoms[i]!=f){
          y1=false;
        }
         if(tops[i]!=q&&bottoms[i]!=q){
          y2=false;
        }
        if(y1==false&&y2==false) return -1;
        if(y1){
            if(tops[i]!=f) t1++;
            if(bottoms[i]!=f)b1++;
        }
        if(y2){
            if(tops[i]!=q) t2++;
            if(bottoms[i]!=q)b2++;
        }
       

       }
        int ans=INT_MAX;
        if(y1) ans=min(ans,min(t1,b1));
        if(y2) ans=min(ans,min(t2,b2));
        return ans;
       
    }
};