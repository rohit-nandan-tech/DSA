class Solution {
  public:
    bool solve(int idx, int sum, vector<int>&arr, vector<vector<int>>&dp){
        if(sum ==0) return 1;
        if(idx < 0) return 0;
        
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        bool notTake = solve(idx-1, sum, arr, dp);
        
        bool take = false;
        
        if(arr[idx] <= sum){
            take = solve(idx - 1, sum - arr[idx], arr, dp);
        }
        
        return dp[idx][sum] = notTake or take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<vector<int>>dp(arr.size(), vector<int>(sum + 1, -1));
        
        return solve(arr.size() - 1, sum, arr, dp);
    }
};