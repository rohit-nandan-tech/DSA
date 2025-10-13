class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&vec){
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == 1)
            return 0;
        if(vec[i][j] != -1) return vec[i][j];

        if(i == 0 and j == 0) return 1;

        return vec[i][j] = solve(i-1, j, grid, vec) + solve(i, j-1, grid, vec);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>>vec(m, vector<int>(n, -1));
        return solve(m-1, n-1, grid, vec);
    }
};