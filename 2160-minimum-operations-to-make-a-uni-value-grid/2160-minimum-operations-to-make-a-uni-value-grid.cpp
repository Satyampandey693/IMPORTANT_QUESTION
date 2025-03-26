class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
            arr.push_back(grid[i][j]);
        }
        sort(arr.begin(),arr.end());
        int i=arr.size()/2;
        int j=0;
        int ans=0;
        while(j<i){
            int p=arr[i]-arr[j];
            if(p%x==0)
            ans+=p/x;
            else return -1;
            j++;
        }
        j=i+1;
        while(j<arr.size()){
           int p=arr[j]-arr[i];
            if(p%x==0)
            ans+=p/x;
            else return -1;
            j++;
        }
        return ans;
    }
};