class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        map<int, int> preSumMap;
        int n=a.size();
        int ans=0;
    int sum = 0;
    int maxLen = 0;
    preSumMap[0]=1;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        int rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end()) {
          ans+=preSumMap[rem];
        }
            preSumMap[sum]++;
    }

    return ans;
    }
};