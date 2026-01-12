class Solution {
public:
    vector<int> nums;
    vector<vector<int>> dp;

    int solve(int curr, int prev) {
        if (curr == nums.size())
            return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        // Option 1: skip current
        int notTake = solve(curr + 1, prev);

        // Option 2: take current (if valid)
        int take = 0;
        if (prev == -1 || nums[curr] % nums[prev] == 0) {
            take = 1 + solve(curr + 1, curr);
        }

        return dp[curr][prev + 1] = max(take, notTake);
    }

    vector<int> largestDivisibleSubset(vector<int>& arr) {
        nums = arr;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        dp.assign(n, vector<int>(n + 1, -1));

        // Step 1: find max length
        solve(0, -1);

        // Step 2: reconstruct subset
        vector<int> ans;
        int curr = 0, prev = -1;

        while (curr < n) {
    int notTake = solve(curr + 1, prev);

    int take = -1;
    if (prev == -1 || nums[curr] % nums[prev] == 0) {
        take = 1 + solve(curr + 1, curr);
    }

    // STRICT comparison + validity check
    if (take > notTake) {
        ans.push_back(nums[curr]);
        prev = curr;
    }

    curr++;
}

        return ans;
    }
};
