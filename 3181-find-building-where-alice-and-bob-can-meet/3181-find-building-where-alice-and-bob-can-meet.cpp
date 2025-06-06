class Solution {
public:
vector<int> arr;
vector<int> segTree;
// vector<int> lazy(400001,0);
void build(int ind,int low,int high){
    if(low==high){
        segTree[ind]=low;
        return ;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    // if()
    // segTree[ind]=max(arr[segTree[2*ind+1]],arr[segTree[2*ind+2]]);//we are storing sum of 
    //left node and right node as this q is related to find sum in range
    if(arr[segTree[2*ind+1]]>=arr[segTree[2*ind+2]]){
      segTree[ind]=segTree[2*ind+1];
    }
    else{
        segTree[ind]=segTree[2*ind+2];
    }

}

int query(int ind,int low,int high,int l,int r){
    if(low>=l&&high<=r){
        return segTree[ind];
    }
    if(high<l||low>r||low>high){
        return -1;
    }
    int mid=(low+high)/2;
    int left=query(2*ind+1,low,mid,l,r);
    int right=query(2*ind+2,mid+1,high,l,r);
    if(right==-1&&left==-1) return -1;
    else if(right==-1){
        return left;
    }
    else if(left==-1) return right;
     if(arr[left]>=arr[right]){
      return left;
    }
    else{
        return right;
    }

}
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        arr=heights;
        int n=heights.size();
        segTree.resize(4*n+1,0);
        build(0,0,n-1);
        vector<int> ans;
        map<int,int> mp;
        for(int i=heights.size()-1;i>=0;i--){
            if(mp[heights[i]]==0)
               mp[heights[i]]=i;
        }
        for(int i=0;i<queries.size();i++){
            int l=min(queries[i][0],queries[i][1]);
            int r=max(queries[i][0],queries[i][1]);
            if(arr[r]>arr[l]||(l==r)){
                ans.push_back(r);
                // cout<<i<<" ";
                // cout<<"N"<<endl;;
                continue;
                
            }
            int st=r+1;
            int e=n-1;
            int mid=st+(e-st)/2;
            int id=-1;
            while(st<=e){
                // cout<<mid;
                int p=query(0,0,n-1,st,mid);
                if(arr[p]>arr[r]&&arr[p]>arr[l]){
                id=p;
                e=mid-1;
                }
                else st=mid+1;
                 mid=st+(e-st)/2;
            }
            ans.push_back(id);  
        }
        return ans;

    }
};