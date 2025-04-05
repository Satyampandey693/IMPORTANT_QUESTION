class Solution {
public:
void calculate(vector<int>& nums,int xorr,int &ans,int i){
    if(i==nums.size()) {
        ans+=xorr;
        return ;
    }
    calculate(nums,xorr,ans,i+1);
    xorr^=nums[i];
    calculate(nums,xorr,ans,i+1);
}
    int subsetXORSum(vector<int>& nums) {
        if(nums.size()==0) return  0;
        int xorr=0;
        int ans=0;
        // for(int i=0;i<nums.size();i++){
        //  xorr=0;
        //  xorr^=nums[i];
        //  cout<<xorr;
        //  ans+=nums[i];
        //  for(int j=i+1;j<nums.size();j++){
        //     xorr^=nums[j];
        //     cout<<" "<<xorr;
        //     ans+=xorr;
        //  }
        //  cout<<endl;
        // }
        // return ans;
        calculate(nums,xorr,ans,0);
        return ans;
    }
};