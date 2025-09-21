class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if (start == end) return 0;
        queue<pair<int,int>> q;
        q.push({start, 0});
        
        int mod = 100000; // सही modulo
        vector<int> dist(mod, 1e9);
        
        dist[start] = 0;
        
        while(!q.empty()){
            auto [node, step] = q.front();
            q.pop();
            
            for(auto a: arr){
                int num = (a * node) % mod;
                
                if(step + 1 < dist[num]){
                    dist[num] = step + 1;
                    
                    if(num == end) return step + 1;
                    q.push({num, step + 1});
                }
            }
        }
        
        return -1;
    }
};
