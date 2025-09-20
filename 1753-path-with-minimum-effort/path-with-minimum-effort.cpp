class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        // Min-heap: {effort, {x,y}}
        priority_queue<pair<int,pair<int,int>>, 
                       vector<pair<int,pair<int,int>>>, 
                       greater<pair<int,pair<int,int>>>> pq;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0,0}});
        
        vector<int> dx = {0, 0, 1 ,-1};
        vector<int> dy = {1 ,-1,0,0};
        
        while(!pq.empty()){
            auto [effort, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;

            // agar destination pohch gaye to return
            if(x == m-1 && y == n-1) return effort;
            
            for(int i=0;i<4;i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n){
                    int newEffort = max(effort, abs(heights[x][y] - heights[nx][ny]));
                    if(newEffort < dist[nx][ny]){
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }

        return 0; // fallback
    }
};
