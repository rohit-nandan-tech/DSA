// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        
        for(int i = 0 ; i <edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int>dist(V, INT_MAX);
        
        dist[src] = 0;
        
        pq.push({dist[src], src});
        
        while(!pq.empty()){
            auto [dis, par] = pq.top();
            pq.pop();
            
            for(auto child: adj[par]){
                if(dist[child.first] >  dist[par] +  child.second){
                    dist[child.first] = dist[par] + child.second;
                    pq.push({dist[child.first], child.first});
                }
            }
        }
        
        return dist;
        
    }
};