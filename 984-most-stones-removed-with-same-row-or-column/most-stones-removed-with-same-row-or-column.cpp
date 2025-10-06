class Solution {
public:
    void dfs(int i, vector<vector<int>>&stones, vector<int>&vis){
        vis[i] = true;

        for(int j = 0; j <stones.size();j++){
            if(vis[j] == 0 && (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])){
                dfs(j, stones, vis);
            }
        }

    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int>vis(n, 0);

        int comp = 0;

        for(int i = 0; i<stones.size();i++){
            if(!vis[i]){
                dfs(i, stones, vis);
                comp++;
            }
        }

        return n - comp;
    }
};