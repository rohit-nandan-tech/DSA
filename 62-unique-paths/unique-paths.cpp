class Solution {
public:
    int solve(int i , int j, vector<vector<int>>&dp, int &step){

        if(i< 0 or j < 0 or i >= dp.size() or j>= dp[0].size()) return 0;
        if(i == 0  and j == 0) {
         
            return 1;
        }

        if(dp[i][j] != -1) return step + dp[i][j];

        return dp[i][j] = solve(i, j-1, dp, step) + solve(i - 1, j, dp, step);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));

        int step = 0;
        return solve(m-1, n-1, dp, step);


    }
};