class Solution {
public:
bool find(string &p,int sum,int i){
    if(sum<0) return false;
   
    if(i==p.size()){
         if(sum==0) return true;
        return false;
    }
    string r;
    bool ans=false;;
    for(int j=i;j<p.size();j++){
          r.push_back(p[j]);
          int t=stoi(r);
          ans|=find(p,sum-t,j+1);
    }
    return ans;

}
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            string p=to_string(sq);
            // int x=0;
          if(find(p,i,0)){
            ans+=sq;
        //   cout<<i<<endl;
        }
        }
        return ans;
    }
};