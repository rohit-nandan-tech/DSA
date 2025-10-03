class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
                if (heightMap.empty() || heightMap[0].empty()) return 0;

        int m = heightMap.size();
        int n = heightMap[0].size();

        // Min-heap: (height, x, y)
        using Cell = tuple<int,int,int>;
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};

        // Push boundary cells into PQ
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }

        int water = 0;

        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            pq.pop();

            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;

                    // If neighbor is lower, water can be trapped
                    if (heightMap[nx][ny] < h) {
                        water += h - heightMap[nx][ny];
                    }

                    // Push the max of current height and neighbor's height
                    pq.push({max(heightMap[nx][ny], h), nx, ny});
                }
            }
        }

        return water;
    }
};