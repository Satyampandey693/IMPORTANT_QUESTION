class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                   long long  va=1ll*(nums[i]-nums[j])*1ll*nums[k];
                    maxi=max(maxi,va);
}
            }
        }
        
        return maxi;
    }
};