class Solution {
public:
    int solve(int i , int j , vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size())
            return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];

        int l = solve(i, j-1, grid, dp);
        int u = solve(i-1, j, grid, dp);

        int mini = min(l, u);

        if(mini == INT_MAX) mini = 0;

        dp[i][j] = grid[i][j] + mini;

        return dp[i][j];

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>>dp(m, vector<int>(n, -1));

        solve(m-1, n-1, grid, dp);

        return dp[m-1][n-1];
    }
};