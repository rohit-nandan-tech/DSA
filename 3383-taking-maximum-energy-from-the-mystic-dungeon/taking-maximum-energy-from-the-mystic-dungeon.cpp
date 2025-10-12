class Solution {
public:

    int solve(int idx, vector<int>&dp, vector<int>&nums, int &k){
        if(idx >= nums.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int inc = nums[idx] + solve(idx + k, dp, nums, k);

        return dp[idx] = inc;
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        vector<int>dp(n, -1);

        int ans = INT_MIN;
        for(int i = 0 ; i < n;i++){
            ans = max(ans,solve(i, dp, energy, k));
        }

        



        return ans;
    }
};