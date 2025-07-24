class Solution {
public:

const int N = 1e5 + 5;

// vector<int> tree=vector<int> arr[N];
vector<vector<int>> tree;

 vector<int> nums, subtreeXor, inTime, outTime, parent;
    int timer = 0, totalXor = 0;



void dfs(int node, int par) {
    subtreeXor[node] = nums[node];
    inTime[node] = ++timer;
    parent[node] = par;

    for (int nei : tree[node]) {
        if (nei == par) continue;
        dfs(nei, node);
        subtreeXor[node] ^= subtreeXor[nei];
    }

    outTime[node] = ++timer;
}

// Check if u is ancestor of v
bool isAncestor(int u, int v) {
    return inTime[u] <= inTime[v] && outTime[v] <= outTime[u];
}

// int minimumScore(vector<int>& numsVec, vector<vector<int>>& edges) {
   
// }
    int minimumScore(vector<int>& numsVec, vector<vector<int>>& edges) {
         int n = numsVec.size();
        //  int n = numsVec.size();
        nums = numsVec;
        subtreeXor.assign(n, 0);
        inTime.assign(n, 0);
        outTime.assign(n, 0);
        parent.assign(n, -1);
        timer = 0;
        tree.resize(n);
    for (int i = 0; i < n; ++i) nums[i] = numsVec[i];

    for (auto& e : edges) {
        int u = e[0], v = e[1];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(0, -1);
    totalXor = subtreeXor[0];

    // Store all removable edges as (child, parent)
    vector<pair<int, int>> edgeList;
    for (int i = 1; i < n; ++i) {
        edgeList.push_back({i, parent[i]});
    }

    int res = INT_MAX;

    for (int i = 0; i < edgeList.size(); ++i) {
        int a = edgeList[i].first;

        for (int j = i + 1; j < edgeList.size(); ++j) {
            int b = edgeList[j].first;

            int xor1 = subtreeXor[a];
            int xor2, xor3;

            if (isAncestor(a, b)) {
                xor2 = subtreeXor[b];
                xor3 = totalXor ^ xor1;
                xor1 ^= xor2;
            }
            else if (isAncestor(b, a)) {
                xor2 = subtreeXor[a];
                xor3 = totalXor ^ subtreeXor[b];
                xor2 ^= subtreeXor[b];
                swap(xor1, xor2);
            }
            else {
                xor2 = subtreeXor[b];
                xor3 = totalXor ^ xor1 ^ xor2;
            }

            int mx = max({xor1, xor2, xor3});
            int mn = min({xor1, xor2, xor3});
            res = min(res, mx - mn);
        }
    }

    return res;
    }
};