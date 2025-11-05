class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {

        if(amt == 0) return 0;
        
        const int INF = 1e9;
        vector<vector<int>>dp(coins.size(), vector<int>(amt + 1, INF));

        for(int i = 0; i < coins.size(); i++)
            dp[i][0] = 0;

        for(int i = 0; i<= amt; i++){
            if(i % coins[0] == 0)
                dp[0][i] = (i/coins[0]);
        }

        for(int i = 1; i < coins.size(); i++){
            for(int j = 1; j <= amt; j++){
                int notTake = dp[i-1][j];

                int take = INF;
                if (coins[i] <= j)
                    take = 1 + dp[i][j - coins[i]]; // take current coin again
                dp[i][j] = min(take, notTake);
            }
        }

        int ans = dp[coins.size() - 1][amt];
        return ans >= INF ? -1 : ans;

        
    } 

};