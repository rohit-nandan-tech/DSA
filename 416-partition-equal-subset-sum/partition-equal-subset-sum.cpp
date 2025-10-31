class Solution {
public:

    bool solve(int idx, int tar, vector<vector<int>> &dp, vector<int> &nums){
        if(tar == 0) return 1;
        if(idx < 0) return 0;

        if(dp[idx][tar] != -1) return dp[idx][tar];

        int notTake = solve(idx - 1, tar, dp, nums);

        int take = 0;
        if(nums[idx] <= tar)
            take = solve(idx - 1, tar - nums[idx], dp, nums);

        return dp[idx][tar] = take or notTake;

    }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if(total & 1) return false;  // if total is odd

        int target = total/2;

        vector<vector<int>>dp(nums.size(), vector<int>(target + 1, -1));

        return solve(nums.size() - 1, target, dp, nums);

    }
};