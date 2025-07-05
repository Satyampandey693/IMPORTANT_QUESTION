class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> v(500+1,0);
        for(int i=0;i<arr.size();i++){
            v[arr[i]]++;
        }
        int ans=-1;
        for(int i=1;i<501;i++){
            if(v[i]==i) ans=i;
        }
        return ans;
    }
};