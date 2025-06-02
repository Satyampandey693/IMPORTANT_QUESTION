class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> can(n,1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++)pq.push({ratings[i],i});
        while(!pq.empty()){
            int i=pq.top().second;
            int cRat=pq.top().first;
            if(i==0&&i==n-1) break;
            if(i==n-1){
                 if(ratings[i-1]<ratings[i]){
                    can[i]=max(can[i],can[i-1]+1);
                }
            }
            else if(i==0){
                if(ratings[i+1]<ratings[i]){
                    can[i]=max(can[i],can[i+1]+1);
                }
            }
            else{
                if(ratings[i-1]<ratings[i]){
                    can[i]=max(can[i],can[i-1]+1);
                }
                 if(ratings[i+1]<ratings[i]){
                    can[i]=max(can[i],can[i+1]+1);
                }
            
            }
             pq.pop(); 


        }
        int ans=accumulate(can.begin(),can.end(),0);
        return ans;
    }
};