class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    //    priority_queue<int,vector<int>,greater<int>> pq;
      int n=startTime.size();
    vector<int> fg;
    vector<int> bg;
      for(int i=0;i<n;i++){
        int d=0;
        if(i==0) d=startTime[i];
        else 
        d=startTime[i]-endTime[i-1];
        fg.push_back(d);
      }
      int p=eventTime-endTime[n-1];
        fg.push_back(p);
    //   bg.push_back(p);
      for(int i=n-1;i>=0;i--){
        int d=0;
        if(i==n-1) d=eventTime-endTime[i];
        // if(i==n-1)
        else d=startTime[i+1]-endTime[i];
     bg.push_back(d);
      }
      p=startTime[0];;
      bg.push_back(p);
    //   cout<<fg.size()<<bg.size();
      for(int i=1;i<n+1;i++){
        // cout<<
        fg[i]+=fg[i-1];
        bg[i]+=bg[i-1];
      }
    //    for(int i=0;i<n+1;i++){
    //     cout<<fg[i]<<" ";
    //     // fg[i]+=fg[i-1];
    //     // bg[i]+=bg[i-1];
    //   }
    //   cout<<endl;
    //    for(int i=0;i<n+1;i++){
    //     cout<<bg[i]<<" ";
    //     // fg[i]+=fg[i-1];
    //     // bg[i]+=bg[i-1];
    //   }

    

       int ans=0;
       int ts=0;
    
     for(int i=0;i<=n;i++){
        if(i>k){
            ans=max(ans,fg[i]-fg[i-k-1]);
            ans=max(ans,bg[i]-bg[i-k-1]);

        }
        else{
            ans=max(ans,fg[i]);
             ans=max(ans,bg[i]);
        }
     }

//        for(int i=0;i<n;i++){
//         int d=0;
//         if(i==0) d=startTime[i];
//         else 
//         d=startTime[i]-endTime[i-1];
//            if(pq.size()<=k){
//             pq.push(d);
//             ts+=d;
//            }
//            else{
//             pq.push(d);
//             int r=pq.top();
//             pq.pop();
//             ts+=(d-r);
//            }
//            ans=max(ans,ts);
//        } 
//         int  d=eventTime-endTime[n-1];
//            if(pq.size()<=k){
//             pq.push(d);
//             ts+=d;
//            }
//            else{
//             pq.push(d);
//             int r=pq.top();
//             pq.pop();
//             ts+=(d-r);
//            }
//            ans=max(ans,ts);
//        while(!pq.empty())pq.pop();
//    ts=0;

//        for(int i=n-1;i>=0;i--){
//         int d=0;
//         if(i==n-1) d=eventTime-startTime[i];
//         // if(i==n-1)
//         else d=startTime[i+1]-endTime[i];
//            if(pq.size()<=k){
//             pq.push(d);
//             ts+=d;
//            }
//            else{
//             pq.push(d);
//             int r=pq.top();
//             pq.pop();
//             ts+=(d-r);
//            }
//            ans=max(ans,ts);
//        } 
//        d=startTime[0];
//            if(pq.size()<=k){
//             pq.push(d);
//             ts+=d;
//            }
//            else{
//             pq.push(d);
//             int r=pq.top();
//             pq.pop();
//             ts+=(d-r);
//            }
//            ans=max(ans,ts);
           return ans;

    }
};