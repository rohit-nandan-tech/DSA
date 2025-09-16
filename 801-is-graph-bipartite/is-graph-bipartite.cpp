class Solution {
public:
    bool dfs(int node, vector<int>&color, vector<vector<int>>&grp){
        for(auto n: grp[node]){
            if(color[n] == -1){
                color[n] = 1 - color[node];
                if(!dfs(n, color, grp)){
                    return false;
                }
            }
            else {
                if(color[n] == color[node]) return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i = 0 ; i < n; i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!dfs(i, color, graph)) return false;
            }
        }

        return true;
    }
};