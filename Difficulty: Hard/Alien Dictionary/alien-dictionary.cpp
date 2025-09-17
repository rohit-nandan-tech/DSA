class Solution {
public:
    string findOrder(vector<string> &words) {
        unordered_map<char, vector<char>> grp;
        unordered_map<char, int> indeg;
        
        // initialize indegree for all chars
        for (auto &w : words) {
            for (auto c : w) {
                indeg[c] = 0;
            }
        }
        
        // build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i+1];
            
            int len = min(w1.size(), w2.size());
            
            // prefix invalid case
            if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) {
                return "";
            }
            
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    grp[w1[j]].push_back(w2[j]);
                    indeg[w2[j]]++;
                    break;
                }
            }
        }
        
        // topo sort (Kahn's)
        queue<char> q;
        for (auto &d : indeg) {
            if (d.second == 0) q.push(d.first);
        }
        
        string s = "";
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            s.push_back(c);
            
            for (auto ch : grp[c]) {
                indeg[ch]--;
                if (indeg[ch] == 0) {
                    q.push(ch);
                }
            }
        }
        
        // if not all chars included, cycle exists
        if (s.size() != indeg.size()) return "";
        
        return s;
    }
};
