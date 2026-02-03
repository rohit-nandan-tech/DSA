class Solution {
public:

    int find(vector<vector<int>>&mat, int col){
        int maxi = INT_MIN;

        int idx = -1;

        for(int i = 0; i< mat.size(); i++){
            if(maxi < mat[i][col]){
                maxi = mat[i][col];
                idx = i;
            }
        }

        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n =  mat[0].size();

        int low =  0, high = n - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            int findMaxIdx = find(mat, mid);

            int left = mid - 1 >=0 ? mat[findMaxIdx][mid-1] : -1;
            int right = mid + 1 <= n-1 ? mat[findMaxIdx][mid + 1]: -1;

            int currEle = mat[findMaxIdx][mid];

            if(currEle > left and currEle > right) return {findMaxIdx, mid};

            if(left > currEle) high = mid - 1;
            else low = mid + 1;
        }

        return {-1, -1};
    }
};