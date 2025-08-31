class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       
        // vector<vector<int>> ans;
        int n=nums.size();
//         set<vector<int>> s;
    
//         for(int i=0;i<nums.size();i++){
//              map<int ,int> m;
//             for(int j=i+1;j<nums.size();j++){
               
//                 int sum=nums[i]+nums[j];
//                 int f=0-sum;
                
//                      vector<int> each;
                
//                 if(m[f]){
//                     int r=nums[m[f]];
//                         each.push_back(nums[i]);
//                         each.push_back(nums[j]);
//                         each.push_back(r);
//                         sort(each.begin(),each.end());
//                          s.insert(each);

//                 }
//                 m[nums[j]]=j;
                   
                  
                
               
//             }
//         }

        
//  for(auto i:s){
//             ans.push_back(i);
//         }
//         return ans;

        //METHOD 2
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++){
        //    if(i!=0&&nums[i]==nums[i-1]) continue;
        //     int j=i+1;
        //     int k=nums.size()-1;
        //     while(j<k){
        //         int sum=nums[i]+nums[j]+nums[k];
        //         if(sum>0) k--;
        //         else if(sum<0) j++;
        //         else{
        //             vector<int> temp={nums[i],nums[j],nums[k]};
        //             ans.push_back(temp);
        //             k--;
        //             j++;

        //         }
        //         //skip the duplicates:
        //         while (j < k && nums[j] == nums[j - 1]) j++;
        //         while (j < k &&k!=nums.size()-1&& nums[k] == nums[k + 1]) k--;
        //     }
        // }

    //      vector<vector<int>> ans;
    // sort(arr.begin(), arr.end());
    // for (int i = 0; i < n; i++) {
    //     //remove duplicates:
    //     if (i != 0 && arr[i] == arr[i - 1]) continue;

    //     //moving 2 pointers:
    //     int j = i + 1;
    //     int k = n - 1;
    //     while (j < k) {
    //         int sum = arr[i] + arr[j] + arr[k];
    //         if (sum < 0) {
    //             j++;
    //         }
    //         else if (sum > 0) {
    //             k--;
    //         }
    //         else {
    //             vector<int> temp = {arr[i], arr[j], arr[k]};
    //             ans.push_back(temp);
    //             j++;
    //             k--;
    //             //skip the duplicates:
    //             while (j < k && arr[j] == arr[j - 1]) j++;
    //             while (j < k && arr[k] == arr[k + 1]) k--;
    //         }
    //     }
    // }
    // return ans;
// }
// sort(ans.begin())
  vector<vector<int>> ans;
  sort(nums.begin(),nums.end());
for(int i=0;i<n;i++){
   //sum of element whose some is -nums[i];
  if(i>0&&nums[i]==nums[i-1]) continue;
   int j=i+1,k=n-1;
   int t=-nums[i];
   while(j<k){
    if(nums[j]+nums[k]==t){
        ans.push_back({nums[i],nums[j],nums[k]});
        j++;
        k--;
    }
     else if(nums[j]+nums[k]>t){
             k--;
     }
     else{
        j++;
     }
     while(j>i+1&&j<n&&nums[j]==nums[j-1])j++;
     while(k<n-1&&j<k&&nums[k]==nums[k+1]) k--;
   }
}
return ans;
        
    }
};