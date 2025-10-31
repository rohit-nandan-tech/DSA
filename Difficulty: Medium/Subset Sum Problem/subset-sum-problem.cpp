class Solution {
  public:
  
    bool solve(int idx, int sum, vector<int>&arr, vector<vector<int>>&dp){
        if(sum == 0) return 1;
        
        if(idx < 0) return 0;
        
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        int notTake = solve(idx - 1, sum, arr, dp);
        
        int take = false;
        
        if(arr[idx] <= sum)
            take = solve(idx - 1, sum - arr[idx], arr, dp);

        
        
        return dp[idx][sum] = take or notTake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        
        vector<vector<int>>dp(arr.size(), vector<int>(sum + 1, -1));
    
        return solve(arr.size() - 1, sum, arr, dp);
        
    }
};