class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //    int i=m-1;
    //    int j=0;
    //    while(i>=0&&j<n){
    //       if(nums1[i]>nums2[j]){
    //         swap(nums1[i],nums2[j]);
    //         i--;
    //         j++;

    //       }
    //       else{
    //         break;
    //       }
    //    }
    //    sort(nums1.begin(),nums1.begin()+m);
    //    sort(nums2.begin(),nums2.end());
     int   i=m;
      int  j=0;
       while(i<n+m){
        nums1[i]=nums2[j];
        i++;
        j++;
       }

    int gap=ceil((n+m)/2.0);
    while(true){
    int i=0;
    int j=gap;
    while(j<m+n){
        if(nums1[i]>nums1[j]) swap(nums1[i],nums1[j]);
        i++;
        j++;
    }
    if(gap==1) break;
    gap=ceil(gap/2.0);
    }

    }
};