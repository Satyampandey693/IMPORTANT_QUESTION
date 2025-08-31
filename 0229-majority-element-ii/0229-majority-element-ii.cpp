class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a=-1,ca=0,b=1,cb=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(ca==0&&nums[i]!=b||nums[i]==a){
                a=nums[i];
                ca++;
                continue;
            }
            else if(cb==0||nums[i]==b){
                     b=nums[i];
                   cb++;
                   continue;
            }
            if(ca) ca--;
           if(cb) cb--;
            // if(nums[i]==)
        }
     ca=0,cb=0;
    //  cout<<a<<b;
    //  cout<<endl<<ca<<" "<<cb;
     for(int i=0;i<n;i++){
        if(nums[i]==a) ca++;
        if(nums[i]==b) cb++;
     }
     int p=n/3;
     if(a==b){
         if(ca>p) return {a};
     else if(cb>p) return {b};
     } 
     if(ca>p&&cb>p) return {a,b};
     else if(ca>p) return {a};
     else if(cb>p) return {b};
     return {};

    }
};