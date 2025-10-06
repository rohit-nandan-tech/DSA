class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, greater<>>pq;

        vector<vector<int>>vis(n, vector<int>(n,0));

        pq.push({grid[0][0],{0,0}});

        vector<int>dx = {0, 0 , 1, -1};
        vector<int> dy = {1, -1, 0 , 0};

        while(!pq.empty()){
            auto [t, coord] = pq.top();
            pq.pop();
            int x = coord.first, y = coord.second;
            if(x == n - 1 and y == n-1) return t;
            if(vis[x][y]) continue;
            vis[x][y] = 1;
            for(int i =0 ;i < 4;i++){
                int nx = x + dx[i] , ny = y + dy[i];
                if(nx >= 0 and ny >=0 and nx < n and ny < n and !vis[nx][ny]){
                    pq.push({max(t,grid[nx][ny]), {nx, ny}});
                }
            }
        }

        return -1;
    }
};