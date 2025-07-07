class Solution {
public:
    int maxEvents(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
    //     int t=1e5+1;;
    //     // vector<int> arr(1e5+1,0);
    //    int ans=0;
    //     for(int i=events.size()-1;i>=0;i--){
    //         int p=events[i][0];
    //         int q=events[i][1];
    //         if(q<t){
    //             t=q;
    //         }
    //         if(q>=t&&p<=t){
    //             ans++;
    //             t--;
    //         }
    //     }
    //     return ans;

     priority_queue<
    pair<int,int>,
    vector<pair<int, int>>,
    greater<pair<int,int>>
> pq;
// for(int i=0;i<arr.size();i++){
//     int p=arr[i][1]-arr[i][0];
//  pq.push({p,{arr[i][1],arr[i]}})
// }
int j=0;
int ans=0;
for(int i=1;i<=1e5;i++){
while(j<arr.size()&&arr[j][0]<=i){
    //  int p=arr[j][1]-arr[j][0];
 pq.push({arr[j][1],arr[j][0]});
    j++;}
    while(!pq.empty()){
        int e=pq.top().first;
        int s=pq.top().second;
        pq.pop();
        if(e<i) continue;
        ans++;
        break;
    }


}
return ans;
    }
};