class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void dfs(vector<vector<int>> &matrix, int i, int j, int prev, vector<vector<int>> &ocean){
        if (i < 0 || i == matrix.size() || j < 0 || j == matrix[0].size() || ocean[i][j] == 1 || matrix[i][j] < prev)
            return;

        ocean[i][j] = 1;
        for (int k = 0; k < 4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            dfs(matrix, nx, ny, matrix[i][j], ocean);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>pacific(m,vector<int>(n,0));
        vector<vector<int>>atlantic(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 or j==0){
                    if(pacific[i][j]==0)
                        dfs(heights,i,j,INT_MIN,pacific);
                }
                if(i==m-1 or j==n-1){
                    if(atlantic[i][j]==0)
                        dfs(heights,i,j,INT_MIN,atlantic);
                }
            }
        }
        
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j]==1 and atlantic[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};