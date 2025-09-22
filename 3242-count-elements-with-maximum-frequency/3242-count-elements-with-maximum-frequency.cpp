class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        long long int maxnum=INT_MIN;
        
         for(int i=0;i<nums.size();i++){
           if(maxnum<nums[i]){
maxnum=nums[i];}
        }
        cout<<maxnum<<" ";
     int size[maxnum+1];
       for(int i=0;i<=maxnum;i++){ 
           size[i]=0;
        }
        
        for(int i=0;i<nums.size();i++){
           size[nums[i]]++;
        }
        long long int max=INT_MIN;
       
         for(int i=0;i<=maxnum;i++){
           if(max<size[i]){
max=size[i];}
        }
        cout<<max<<" ";
        int count=0;
          for(int i=0;i<=maxnum;i++){ 
           if(max==size[i]){
count+=max;}
        }
        
        
        return count;
    }
};