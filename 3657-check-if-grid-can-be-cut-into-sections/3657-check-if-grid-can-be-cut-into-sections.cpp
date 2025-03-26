class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {

        vector<vector<int>> hor;
        vector<vector<int>> ver;
        for(int i=0;i<rectangles.size();i++){
            hor.push_back({min(rectangles[i][0],rectangles[i][2]),max(rectangles[i][0],rectangles[i][2])});
            ver.push_back({min(rectangles[i][1],rectangles[i][3]),max(rectangles[i][1],rectangles[i][3])});
        }
        sort(hor.begin(),hor.end());
        sort(ver.begin(),ver.end());
        bool ans=false;
        int t=0;
        int maxi=hor[0][1];
        for(int i=1;i<hor.size();i++){
            if(hor[i][0]>=maxi) t++;
            maxi=max(maxi,hor[i][1]);

        }
        // cout<<t<<endl;
        if(t>=2) ans=true;
        maxi=ver[0][1];
        t=0;
         for(int i=1;i<hor.size();i++){
            if(ver[i][0]>=maxi) t++;
            maxi=max(maxi,ver[i][1]);
        }
        // cout<<t;
        if(t>=2) ans=true;
        return ans;


    }
};