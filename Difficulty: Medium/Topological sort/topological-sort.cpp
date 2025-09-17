class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(V);
        
        vector<int>indeg(V,0);
        
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }
        
        queue<int>q;
        
        for(int i =  0 ; i  < indeg.size();i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        
        vector<int>ans;
        
        while(!q.empty()){
            int f = q.front();
            q.pop();
            
            for(auto n : adj[f]){
                indeg[n]--;
                if(indeg[n] == 0){
                    q.push(n);
                }
            }
            
            ans.push_back(f);
        }
        return ans;
    }
};