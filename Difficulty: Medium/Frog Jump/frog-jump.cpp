class Solution {
  public:
  
    int climb(int n, vector<int>&height, vector<int>&dp){
        if(n <= 0) return 0;
        
        if(dp[n] != INT_MAX) return dp[n];
        int left = climb(n-1, height, dp) + abs(height[n] - height[n-1]);
        int right = INT_MAX;
        if(n > 1)
            right = climb(n-2, height, dp) + abs(height[n] - height[n-2]);
        
        return dp[n] =  min(left, right);
    }
    int minCost(vector<int>& height) {
        vector<int>dp(height.size(), INT_MAX);
        
        climb(height.size()-1, height, dp);
        
        if(dp[height.size() - 1] == INT_MAX) return 0;
        
        return dp[height.size()-1];
        
    }
};