// User function Template for C++

class Solution {
public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // dp array represent karta hai har leaf ka state: 0 = unvisited, 1 = visited
        vector<int> dp(leaves + 1, 0);

        for (int i = 0; i < N; i++) {
            int jump = frogs[i];

            // agar frog ka jump 0 hai ya leaves se bada hai to skip kar do
            if (jump == 0 || jump > leaves) continue;

            // agar frog ka first jump hi visited hai to matlab ye frog ka kaam pehle ho gaya tha
            if (dp[jump] == 1) continue;

            // frog apne multiples pe jump karega aur dp me mark karega
            for (int j = jump; j <= leaves; j += jump) {
                dp[j] = 1; // leaf visited
            }
        }

        // ab count karo unvisited leaves
        int count = 0;
        for (int i = 1; i <= leaves; i++) {
            if (dp[i] == 0) count++;
        }

        return count;
    }
};

