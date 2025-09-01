class Solution {
public:
      #define ll long long 
      int ti=0;
   
  void merge(int l,int r,int mid,vector<int> &arr){
      int i=l;
      int m=mid+1;
      int j=mid+1;
      int n=r+1;
      while(i<m&&j<n){
          if(1ll*arr[i]>2*1ll*arr[j]){
              ti+=(m-i);
              j++;
          }
          else{
              i++;
          }
      }
      vector<int> ans;
      i=l,j=mid+1;
      while(i<m&&j<n){
          if(arr[i]>arr[j]){
              ans.push_back(arr[j]);
              j++;
          }
          else{
              ans.push_back(arr[i]);
              i++;
          }
      }
      while(i<m){
           ans.push_back(arr[i]);
              i++;
      }
       while(j<n){
           ans.push_back(arr[j]);
              j++;
      }
      for(i=l;i<r+1;i++){
          arr[i]=ans[i-l];
      }
      
  }
  void mergeSort(int i,int j,vector<int> &arr){
      if(i>=j){
          return;
      }
      int mid=i+(j-i)/2;
      mergeSort(i,mid,arr);
      mergeSort(mid+1,j,arr);
      merge(i,j,mid,arr);
  }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
     mergeSort(0,n-1,nums);
     return ti;
    }
};
