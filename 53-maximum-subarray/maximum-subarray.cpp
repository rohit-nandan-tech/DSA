class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int overallsum = INT_MIN, currentsum = 0;
        for(int i = 0;i< nums.size();i++){
            currentsum+=nums[i];
            overallsum = max(overallsum, currentsum);
            if(currentsum < 0)
                currentsum = 0;
        }

        return overallsum;
    }
};