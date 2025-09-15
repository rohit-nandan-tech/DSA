class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // mark broken letters in a boolean array
        vector<bool> broken(26, false);
        for (char c : brokenLetters) {
            broken[c - 'a'] = true;
        }

        int count = 0;
        bool canType = true;

        for (char c : text) {
            if (c == ' ') {
                if (canType) count++;
                canType = true; // reset for next word
            } else if (broken[c - 'a']) {
                canType = false;
            }
        }

        // handle last word
        if (canType) count++;

        return count;
    }
};
