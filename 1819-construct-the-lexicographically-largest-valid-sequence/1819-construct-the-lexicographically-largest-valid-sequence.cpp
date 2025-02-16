class Solution {
public:
    vector<int> vis;
    
    bool find(vector<int> &ans, int i, int c, int n) {
        if (c == n) return true;  // Successfully placed all numbers
        if (i >= 2 * n - 1) return false;  // Out of bounds
        
        if (ans[i] != 0) return find(ans, i + 1, c, n);  // Skip filled positions
        
        for (int j = n; j > 0; j--) {  // Start from largest number for lexicographically largest
            if (vis[j] == 0) {  
                if (j == 1) {  // Special case: 1 appears only once
                    ans[i] = j;
                    vis[j] = 1;
                    if (find(ans, i + 1, c + 1, n)) return true;
                    ans[i] = 0;  // Backtrack
                    vis[j] = 0;
                } 
                else if (i + j < 2 * n - 1 && ans[i + j] == 0) {  
                    ans[i] = ans[i + j] = j;
                    vis[j] = 1;
                    if (find(ans, i + 1, c + 1, n)) return true;
                    ans[i] = ans[i + j] = 0;  // Backtrack
                    vis[j] = 0;
                }
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vis.resize(n + 1, 0);
        vector<int> ans(2 * n - 1, 0);
        find(ans, 0, 0, n);  // Start from index 0
        return ans;
    }
};
