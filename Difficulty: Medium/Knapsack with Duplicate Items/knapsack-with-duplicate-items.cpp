class Solution {
  public:
  
    vector<int> wt, val;
    vector<vector<int>> memo;
    int n;

    int solve(int i, int cap) {
        if (cap == 0 || i == n) return 0;

        if (memo[i][cap] != -1) return memo[i][cap];

        int notTake = solve(i + 1, cap);
        int take = 0;

        if (wt[i] <= cap) {
            take = val[i] + solve(i, cap - wt[i]); // unbounded
        }

        return memo[i][cap] = max(take, notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        this->wt = wt;
        this->val = val;
        n = wt.size();
        memo.assign(n, vector<int>(capacity + 1, -1));
        return solve(0, capacity);
    }
};