class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto child : adj[node]) {
            if (!vis[child]) {
                if (dfs(child, vis, pathVis, adj)) return true;
            }
            else if (pathVis[child]) {
                return true; // cycle मिला
            }
        }

        pathVis[node] = 0; // backtrack करते समय path से निकाल दो
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& n : edges) {
            adj[n[0]].push_back(n[1]); // directed edge
        }

        vector<int> vis(V, 0), pathVis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis, adj)) return true;
            }
        }
        return false;
    }
};
