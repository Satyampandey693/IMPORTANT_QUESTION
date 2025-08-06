class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
       int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        // Min-heap: (maxTimeSoFar, row, col)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        pq.push({grid[0][0], 0, 0});
        vector<int> dr = {0, 0, 1, -1};
        vector<int> dc = {1, -1, 0, 0};

        while (!pq.empty()) {
            auto [time, r, c] = pq.top();
            pq.pop();

            if (visited[r][c]) continue;
            visited[r][c] = true;

            if (r == n - 1 && c == n - 1)
                return time;

            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    int nextTime = max(time, grid[nr][nc]);
                    pq.push({nextTime, nr, nc});
                }
            }
        }

        return -1; // Should not reach here
    }
};