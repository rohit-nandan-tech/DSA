
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,long long> mp;
        for(int p : power) mp[p] += p;

        vector<int> vec;
        for(auto &m : mp) vec.push_back(m.first);
        sort(vec.begin(), vec.end());

        int n = vec.size();
        if(n == 0) return 0;

        vector<long long> dp(n, 0);
        dp[0] = mp[vec[0]];

        for(int i = 1; i < n; i++) {
            // Find the last index j < i such that vec[i] - vec[j] > 2
            int j = i-1;
            while(j >= 0 && vec[i] - vec[j] <= 2) j--;

            long long take = mp[vec[i]] + (j >= 0 ? dp[j] : 0);
            long long skip = dp[i-1];

            dp[i] = max(take, skip);
        }

        return dp[n-1];
    }
};


