class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
       int n = nums.size();
    int minLen = INT_MAX;

    vector<long long> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }

    // Min-heap comparing prefixSum values
    // auto cmp = [&](int a, int b) {
    //     return prefixSum[a] > prefixSum[b];
    // };
    // priority_queue<int, vector<int>, decltype(cmp)> minHeap(cmp);

    deque<int> dq;

    for (int i = 0; i <= n; i++) {
        // while (!minHeap.empty() && prefixSum[i] - prefixSum[minHeap.top()] >= k) {
        //     minLen = min(minLen, i - minHeap.top());
        //     minHeap.pop();
        // }
        // minHeap.push(i);
        while(!dq.empty()&&prefixSum[i] - prefixSum[dq.front()] >= k){
             minLen = min(minLen, i - dq.front());
           dq.pop_front(); 
        }
        // while(!dq.empty()&&prefixSum[i]<=prefixSum[dq.front()] ) dq.pop_front();
        // if(!dq.empty()&&prefixSum[i]<=prefixSum[dq.front()])
        // if(dq.empty())dq.push_front(i);
        // else{
            while(!dq.empty()&&prefixSum[i]<=prefixSum[dq.back()] ) dq.pop_back();
            dq.push_back(i);
        // }

    }

    return minLen == INT_MAX ? -1 : minLen;
    }
};