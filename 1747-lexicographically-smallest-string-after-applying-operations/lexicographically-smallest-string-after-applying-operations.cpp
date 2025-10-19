class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
         queue<string> q;
        unordered_set<string> visited;
        string result = s;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            // update result if we found a smaller string
            result = min(result, cur);

            // 1️⃣ Operation 1: Add 'a' to all odd indices
            string added = cur;
            for (int i = 1; i < s.size(); i += 2) {
                added[i] = ((added[i] - '0' + a) % 10) + '0';
            }
            if (!visited.count(added)) {
                visited.insert(added);
                q.push(added);
            }

            // 2️⃣ Operation 2: Rotate right by b
            string rotated = cur.substr(s.size() - b) + cur.substr(0, s.size() - b);
            if (!visited.count(rotated)) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }
        return result;
    }
};