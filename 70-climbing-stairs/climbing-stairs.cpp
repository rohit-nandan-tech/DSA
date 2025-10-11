class Solution {
public:

    int climb(int n , vector<int>&dp){
        if(n <= 1) return dp[n] = 1;
        dp[n-2] = dp[n-2] == -1 ? climb(n-2, dp) : dp[n-2];
        dp[n-1] = dp[n-1] == -1 ? climb(n-1, dp) : dp[n-1];

        return dp[n] = dp[n-2] + dp[n-1];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);

        climb(n, dp);
        return dp[n];
    }
};