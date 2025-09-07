class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // int s = 1;
        // int e = 2000;
        // int ans = -1;

        // while (s <= e) {
        //     int mid = s + (e - s) / 2;

        //     // Count how many numbers are missing <= mid
        //     int missing = mid;
        //     int actual = upper_bound(piles.begin(), piles.end(), mid) - piles.begin();
        //     missing -= actual;

        //     if (missing < k) {
        //         s = mid + 1;
        //     } else {
        //         ans = mid; // potential answer
        //         e = mid - 1;
        //     }
        // }
        // return ans;
        if(k<arr[0]) return k;
        int p=arr[0]-1;
        int c=p;
        int ans=0;
        for(int i=1;i<arr.size();i++){
            p=arr[i]-arr[i-1]-1;
            if(c+p>=k){
                int r=k-c;
                ans=arr[i-1]+r;
                c=k+11;
                break;
            }
            c+=p;
        }
        if(c<=k){
            ans=arr[arr.size()-1]+(k-c);
        }
        return ans;

    }
};
