class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        map<int,int> mp;
        int n=startTime.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int r=startTime[i];
            if(i>0)r-=endTime[i-1];
            int s;
            if(i==n-1){
                s=eventTime-endTime[i];
            }
            else{
                s=startTime[i+1]-endTime[i];
            }
            int p=s+r;

             if(mp.lower_bound(endTime[i]-startTime[i])!=mp.end()){
                p+=endTime[i]-startTime[i];
             }
             ans=max(ans,p);
             mp[r]++;
        }
        map<int,int> m;
         for(int i=n-1;i>=0;i--){
            int r=startTime[i];
            if(i>0)r-=endTime[i-1];
            int s;
            if(i==n-1){
                s=eventTime-endTime[i];
            }
            else{
                s=startTime[i+1]-endTime[i];
            }
            int p=s+r;

             if(m.lower_bound(endTime[i]-startTime[i])!=m.end()){
                p+=endTime[i]-startTime[i];
             }
             ans=max(ans,p);
             m[s]++;
        }
        return ans;

    
    }
};