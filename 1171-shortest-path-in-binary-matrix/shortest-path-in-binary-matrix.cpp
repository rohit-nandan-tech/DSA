class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>>q;
        q.push({0, 0});
        int cnt = 0;
        vis[0][0] = 1;
        

        vector<int>dx = {0, 0, -1 , -1 , -1, 1 , 1 , 1};
        vector<int>dy = {1 , -1, 1 , 0, -1 , 1 , 0, -1};

        int destX = m - 1, destY = n - 1;

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            if(destX == x and destY == y)
                return vis[x][y];
            for(int i = 0 ; i < 8 ; i++){
                int nx = x + dx[i], ny = y + dy[i];
             
                if(nx >= 0 and ny >= 0 and 
                nx < m and ny < n and vis[nx][ny] > vis[x][y] + 1 and grid[nx][ny] != 1){
                    vis[nx][ny] = vis[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return -1;

        
    }
};