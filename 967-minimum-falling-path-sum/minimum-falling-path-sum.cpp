class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m = mat.size();
        vector<vector<int>>dp = mat;   

        for(int i = 1; i < m; i++){
            for(int j = 0; j < m ; j++){
                int up = dp[i-1][j];
                int leftDiag = j > 0 ? dp[i-1][j-1] : INT_MAX;
                int rightDiag = j < m -1 ? dp[i-1][j+1] : INT_MAX;

                dp[i][j] += min(up , min(leftDiag, rightDiag)); 
            }
        }

        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};