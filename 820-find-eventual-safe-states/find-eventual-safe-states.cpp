class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& pre) {
        int num = pre.size();
        vector<vector<int>>adj(num);
        vector<int>indeg(num, 0);
        for(int i = 0 ; i <pre.size();i++){
            for(auto n: pre[i]){
                adj[n].push_back(i);
                indeg[i]++;
            }
        }

        queue<int>q;
        for(int i = 0 ; i<num;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }


     

        vector<int>ans;
        while(!q.empty()){
            int f = q.front();
            q.pop();

            for(auto n: adj[f]){
                indeg[n]--;
                if(indeg[n]==0){
                    q.push(n);
                }
            }
            ans.push_back(f);
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};