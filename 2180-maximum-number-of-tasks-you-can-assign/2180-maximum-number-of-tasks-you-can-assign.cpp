class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
       int s=0;
      
       int n=tasks.size();
       int m=workers.size();
       int e=min(m,n);
       int mid=s+(e-s)/2;
       int ans=0;

       while(s<=e){
        int ex=0;
        multiset<int> workersFree(workers.end() - mid, workers.end());
      for(int i = mid - 1; i >= 0; --i) {
    auto it = prev(workersFree.end());
    
    if(*it < tasks[i]) {
        it = workersFree.lower_bound(tasks[i] - strength);
        if(it == workersFree.end()) {
            ex=1e7;
            break;
        }
    ex++;
    if (ex > pills) {
        break;
        }
    }
    workersFree.erase(it);
}
        if(mid==3) cout<<ex;
        if(ex<=pills){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
            
        }
        mid=s+(e-s)/2;
       }
       return ans;
    }
};