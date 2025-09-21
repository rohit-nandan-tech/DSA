class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n +1);
        for (auto &f : times) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        vector<int>dist(n + 1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();

            for(auto child: adj[node]){
                if(time + child.second < dist[child.first]){
                    dist[child.first]  = time + child.second;
                    pq.push({dist[child.first], child.first});
                }
            }
        }

        int ans = -1;

        for(int i = 1 ; i<=n;i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        

        return ans;

        
    }
};