class DSU{
    vector<int> par, rank;
public:
    DSU(int n){
        par.resize(n);
        rank.resize(n, 0);

        for(int i = 0 ; i < n ; i++){
            par[i] = i;
        }
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }
        return find(par[x]);
    }

    void unionFunc(int x, int y){
        int parX = find(x);
        int parY = find(y);
        if(parX == parY) return;
        if(rank[parX] < rank[parY]) par[parX] = parY;
        else if(rank[parY] < rank[parX]) par[parY] = parX;
        else{
            par[parX] = parY;
            rank[parY]+=1;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& conn) {
        if(conn.size() < n-1) return -1;

        DSU dsu(n);
        for(auto c: conn){
            dsu.unionFunc(c[0], c[1]);
        }

        int ans = 0;

        unordered_set<int> roots;
        for (int i = 0; i < n; i++) {
            roots.insert(dsu.find(i)); // har node ka root daal diya set me
        }
        return (int)roots.size() - 1;
    }
};