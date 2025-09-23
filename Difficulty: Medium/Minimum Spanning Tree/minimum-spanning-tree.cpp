class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto e: edges){
           adj[e[0]].push_back({e[1], e[2]});
           adj[e[1]].push_back({e[0], e[2]});
        }
        vector<int>vis(V,0);
        int sum = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        q.push({0,0});
        
        
        
        while(!q.empty()){
            auto [wgt, par] = q.top();
            q.pop();
            if(vis[par] == 1) continue;
            vis[par] = 1;
            sum+=wgt;
            
            for(auto child: adj[par]){
                if(vis[child.first] !=1){
                    q.push({child.second, child.first});
                }
            }
        }
        
        return sum;
    }
};