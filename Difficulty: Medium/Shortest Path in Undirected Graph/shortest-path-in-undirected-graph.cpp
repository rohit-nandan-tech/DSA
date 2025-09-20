class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V = adj.size() ;
        
        vector<int>dist(V, -1);
        
        queue<int>q;
        q.push(src);
        dist[src] = 0;
        
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto neig : adj[front]){
                if(dist[neig] == -1){
                    dist[neig] = dist[front] + 1;
                    q.push(neig);
                } 
            }
        }
        
        return dist;
        
        
    }
};