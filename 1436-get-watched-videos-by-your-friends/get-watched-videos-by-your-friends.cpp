class Solution {
public:

    vector<string> watchedVideosByFriends(
    vector<vector<string>>& watchedVideos,
    vector<vector<int>>& friends,
    int id,
    int level
) {
    int n = watchedVideos.size();

    vector<int> vis(n, 0);
    queue<int> q;

    q.push(id);
    vis[id] = 1;

    int currLevel = 0;

    unordered_map<string, int> mp;

    while (!q.empty()) {

        int sz = q.size();  // current level ke log

        // jab target level aa gaya
        if (currLevel == level) {
            // sirf is level ke logon ke videos count karo
            for (int i = 0; i < sz; i++) {
                int person = q.front();
                q.pop();

                for (string &v : watchedVideos[person]) {
                    mp[v]++;
                }
            }
            break; // BFS yahin khatam
        }

        // normal BFS expansion
        for (int i = 0; i < sz; i++) {
            int person = q.front();
            q.pop();

            for (int dost : friends[person]) {
                if (!vis[dost]) {
                    vis[dost] = 1;
                    q.push(dost);
                }
            }
        }

        currLevel++;
    }

    // sort by frequency then lexicographically
    vector<pair<int, string>> temp;
    for (auto &p : mp) {
        temp.push_back({p.second, p.first});
    }

    sort(temp.begin(), temp.end());

    vector<string> ans;
    for (auto &p : temp) {
        ans.push_back(p.second);
    }

    return ans;
}
};