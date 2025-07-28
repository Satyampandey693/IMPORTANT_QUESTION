class Solution {
public:
int maxor;
int ans;
void find(int i,vector<int> &nums,int currentOr){
   
    if(i==nums.size()) return ;

int p= currentOr;
//not select
find(i+1,nums, currentOr);

    //select
     currentOr= currentOr|nums[i];
      if( currentOr==maxor) ans++;
    find(i+1,nums, currentOr);

}
    int countMaxOrSubsets(vector<int>& nums) {

     
    maxor=0;
    int n=nums.size();
         for(int i=0;i<n;i++){
            maxor|=nums[i];
        }
    ans=0;
    find(0,nums,0);
    return ans;

    }
};