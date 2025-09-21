class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        // Graph banate hain
        vector<vector<pair<int,int>>> adj(n);
        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        // Dijkstra
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0}); // {time, node}

        while (!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();

            for (auto &edge : adj[u]) {
                int v = edge.first;
                long long wt = edge.second;

                if (time + wt < dist[v]) {
                    dist[v] = time + wt;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if (time + wt == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};
