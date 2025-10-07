class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), -1);
        unordered_map<int, int> lastRain; // lake -> last day it rained
        vector<int> dryDays; // indices of zero days

        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] > 0) {
                int lake = rains[i];
                if (lastRain.find(lake) != lastRain.end()) {
                    int prev = lastRain[lake];
                    int dryIndex = -1;

                    // find a dry day after 'prev'
                    for (int j = 0; j < dryDays.size(); j++) {
                        if (dryDays[j] > prev) {
                            dryIndex = dryDays[j];
                            dryDays.erase(dryDays.begin() + j);
                            break;
                        }
                    }

                    if (dryIndex == -1)
                        return {}; // flood — no valid dry day

                    ans[dryIndex] = lake; // dry this lake that day
                }
                lastRain[lake] = i;
                ans[i] = -1;
            } else {
                dryDays.push_back(i);
            }
        }

        // fill remaining 0s with 1 (dry any lake)
        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] == 0 && ans[i] == -1)
                ans[i] = 1;
        }

        return ans;
    }
};