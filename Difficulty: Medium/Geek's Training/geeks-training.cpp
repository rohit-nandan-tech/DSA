class Solution {
  public:
  
    int solve(int day, int last, vector<vector<int>>&arr, vector<vector<int>>&dp){
        
    
        if(day == 0){
            
            // cout<<"hello";
            int maxi = 0;
            for(int i = 0; i < 3;i++){
                if (i != last)
                    maxi = max(maxi, arr[0][i]);
            }
            return maxi;
        }
        // 
        // cout<<dp[day][last]<<"\n";
        
        if(dp[day][last] != -1) return dp[day][last];
        
        int ans = 0;
        
        for(int i = 0 ; i<3; i++){
            if(last != i){
                
                ans = max(ans, arr[day][i] + solve(day -1, i, arr, dp));
            }
        }
        
        // cout<<ans<<"\n";
        
        return dp[day][last] = ans;
        
        
    }
    int maximumPoints(vector<vector<int>>& arr) {
        int days = arr.size();
        vector<vector<int>>dp(days, vector<int>(4, -1));
    
        return solve(days - 1, 3, arr, dp);
    
        
    }
};