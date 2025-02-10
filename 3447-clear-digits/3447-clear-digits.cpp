class Solution {
public:
    string clearDigits(string nums) {
        for(int i=0;i<nums.size();i++){
            int r=nums[i];
            if((int)nums[i]>=48&&(int)nums[i]<=57){
                nums[i]='$';
                for(int j=i-1;j>=0;j--){
                    if((int)nums[j]>=97&&(int)nums[j]<=122){
                        // cout<<
                        nums[j]='$'; break;
                }}
            }
        }
        string ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]=='$') continue;
            ans+=nums[i];
        }
        return ans;
    }
};