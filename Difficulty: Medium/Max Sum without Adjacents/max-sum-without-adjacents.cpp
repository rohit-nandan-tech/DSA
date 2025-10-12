// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    
    
    int summ(int n, vector<int>&arr, vector<int>&dp){
        if(n >= arr.size())  return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int inc = arr[n] + summ(n + 2, arr, dp);
        int exc = summ(n+ 1, arr, dp);
        
        return dp[n] = max(inc, exc);
    }
    int findMaxSum(vector<int>& arr) {
        vector<int>dp(arr.size(), -1);
        
        summ(0, arr, dp);
        
        int maxi = *max_element(dp.begin(), dp.end());
        
        
        return maxi == -1 ? 0 : maxi;
    }
};