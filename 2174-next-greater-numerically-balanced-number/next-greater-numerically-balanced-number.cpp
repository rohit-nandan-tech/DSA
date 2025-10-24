
class Solution {
public:
    int nextBeautifulNumber(int n) {
        const int LIMIT = 10000000; // 1e7 - safe upper bound for our use (covers known next values)
        set<int> results;

        // iterate all non-empty subsets of digits 1..9
        for (int mask = 1; mask < (1 << 9); ++mask) {
            vector<int> digits;
            // build the multiset for this subset
            for (int d = 1; d <= 9; ++d) {
                if (mask & (1 << (d - 1))) {
                    // include digit d exactly d times
                    for (int k = 0; k < d; ++k) digits.push_back(d);
                }
            }

            // If too long, minimal permutation will likely exceed LIMIT; but check minimal value
            sort(digits.begin(), digits.end()); // ascending gives minimal numeric ordering (smallest leading digit)
            long long minVal = 0;
            for (int dig : digits) {
                minVal = minVal * 10 + dig;
                if (minVal > LIMIT) break;
            }
            if (minVal > LIMIT) continue; // skip large multisets

            // generate all unique permutations of this multiset
            // digits is currently sorted (first permutation)
            do {
                // leading digit cannot be 0 (we never include zero), so safe
                long long val = 0;
                for (int dig : digits) {
                    val = val * 10 + dig;
                    if (val > LIMIT) break; // stop early if number exceeds LIMIT
                }
                if (val <= LIMIT) results.insert((int)val);
            } while (next_permutation(digits.begin(), digits.end()));
        }

        // convert set to sorted vector and find next greater than n
        auto it = results.upper_bound(n);
        if (it != results.end()) return *it;
        return -1; // if none found within LIMIT
    }
};