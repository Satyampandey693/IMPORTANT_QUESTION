class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> v(26,0);
        for(int i=0;i<word.size();i++){
            v[word[i]-'a']++;
        }
        int ans=INT_MAX;
        vector<int> arr;

        for(int i=0;i<26;i++){
            if(v[i]==0) continue;
           arr.push_back(v[i]);
        }
        sort(arr.begin(),arr.end());

       for(int i=0;i<arr.size();i++){
        int c=0;
        for(int j=0;j<arr.size();j++){
             if(arr[j]<arr[i]) c+=arr[j];
             if(arr[i]+k<arr[j]) c+=(arr[j]-(arr[i]+k));
        }
        ans=min(ans,c);
       }
       return ans;
    }
};