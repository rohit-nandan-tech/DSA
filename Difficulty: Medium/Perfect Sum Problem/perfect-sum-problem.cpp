class Solution {
public:
    int solve(int idx, int tar, vector<vector<int>>& dp, vector<int>& arr) {
        if (idx == 0) {
            if (tar == 0 && arr[0] == 0) return 2;
            if (tar == 0 || arr[0] == tar) return 1;
            return 0;
        }

        if (dp[idx][tar] != -1) return dp[idx][tar];

        int notTake = solve(idx - 1, tar, dp, arr);
        int take = 0;
        if (arr[idx] <= tar)
            take = solve(idx - 1, tar - arr[idx], dp, arr);

        return dp[idx][tar] = take + notTake;
    }

    int perfectSum(vector<int>& arr, int tar) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
        return solve(n - 1, tar, dp, arr);
    }
};