class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
    for(auto &e : edges){
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); // bi-directional
    }

    int minCount = n;
    int ans = -1;

    // 2. हर city से Dijkstra
    for(int src = 0; src < n; src++){
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        while(!pq.empty()){
            pair<int,int> p = pq.top(); pq.pop();
            int d = p.first;
            int u = p.second;

            if(d > dist[u]) continue;

            for(auto &edge : adj[u]){
                int v = edge.first;
                int w = edge.second;
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // 3. Count cities within threshold
        int count = 0;
        for(int i = 0; i < n; i++){
            if(i != src && dist[i] <= distanceThreshold)
                count++;
        }

        // 4. Update answer
        if(count <= minCount){ // tie → largest city number
            minCount = count;
            ans = src;
        }
    }

    return ans;

    }
};