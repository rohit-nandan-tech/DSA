class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>>adj(num);
        vector<int>indeg(num, 0);
        for(auto n: pre){
            adj[n[1]].push_back(n[0]);
            indeg[n[0]]++;
        }

        queue<int>q;
        for(int i = 0 ; i<num;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }


        int cnt = 0;

        while(!q.empty()){
            int f = q.front();
            q.pop();

            for(auto n: adj[f]){
                indeg[n]--;
                if(indeg[n]==0){
                    q.push(n);
                }
            }
            cnt++;
        }

        return cnt == num;

    }
};