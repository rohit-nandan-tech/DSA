class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> freq(value, 0); // remainder count store karne ke liye

        // Step 1: Har number ka remainder count karo
        for (int num : nums) {
            int rem = ((num % value) + value) % value; // handle negative nums
            freq[rem]++;
        }

        int mex = 0;

        // Step 2: MEX find karo
        while (true) {
            int rem = mex % value;
            if (freq[rem] > 0) {
                freq[rem]--;
                mex++;
            } else {
                return mex;
            }
        }
    }
};