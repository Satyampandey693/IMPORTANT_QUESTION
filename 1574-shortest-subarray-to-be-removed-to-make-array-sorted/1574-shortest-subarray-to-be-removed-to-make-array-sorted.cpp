class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int p=1;
        int q=1;
        int n=arr.size();
        for(int i=1;i<arr.size();i++){
            if(arr[i]>=arr[i-1]) p++;
            else break;
        }
        for(int i=arr.size()-2;i>=0;i--){
          if(arr[i]<=arr[i+1]) q++;
          else break;
        }
        
        int result=min(n-p,n-q);
        cout<<p<<" "<<q;
        int i=0,j=n-q;
        int l=0;
        while(i<p&&j<n&&i<j){
            // if(i>0&&arr[i]<arr[i-1]) break;
            // if(j<arr.size()-1&&arr[j]>arr[j+1]) break;
           if(arr[i]<=arr[j]){
            result=min(result,n-(i+n-j+1));
              i++;;
           }
           else{
            j++;
           }
        } 
        return result;

    }
};