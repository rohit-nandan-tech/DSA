class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
       
        for(int i=0;i<n;i++)dp[i][0]=1;
        
        if(target>=arr[0])dp[0][arr[0]]+=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                int p=(arr[i]<=j)?dp[i-1][j-arr[i]]:0;
                int np=dp[i-1][j];
                dp[i][j]=p+np;
            }
        }
        return dp[n-1][target];
    }
};