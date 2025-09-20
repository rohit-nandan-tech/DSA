// User function Template for C++
class Solution {
  public:
  
    void toposort(int src, vector<vector<pair<int,int>>>&adj, vector<int>&vis, vector<int>&sorted){
        
        vis[src] = 1;
        for(auto node : adj[src]){
            if(!vis[node.first]){
                toposort(node.first, adj, vis, sorted);
            }
        }
        
        sorted.push_back(src);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(V);
        
        for(int i = 0 ; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        vector<int>vis(V , 0);
        
        vector<int>sorted;
        
        for(int i = 0 ; i  < V;i++){
            if(!vis[i])
                toposort(i, adj, vis, sorted);
        }
        reverse(sorted.begin(), sorted.end());

        vector<int>dist(V,-1);
        dist[0] = 0;  
        
        for(int i = 0 ; i < sorted.size(); i++){
            if(dist[sorted[i]] != -1){ // only relax if reachable
                for(auto neig: adj[sorted[i]]){
                    if(dist[neig.first] == -1)
                        dist[neig.first] = dist[sorted[i]] + neig.second;
                    else
                        dist[neig.first] = min(dist[neig.first], dist[sorted[i]] + neig.second);
                }
            }
        }
        
        return dist;
        
        
        
    }
};
