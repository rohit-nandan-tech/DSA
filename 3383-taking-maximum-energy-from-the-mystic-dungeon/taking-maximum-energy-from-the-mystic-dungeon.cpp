class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<long long> dp(n, 0);

        // Peeche se bharo dp (kyunki dp[i] depends on dp[i+k])
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = energy[i];
            if (i + k < n) {
                dp[i] += dp[i + k]; // jump wala add kar do
            }
        }

        // Ab sabme se max energy choose karo
        long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};