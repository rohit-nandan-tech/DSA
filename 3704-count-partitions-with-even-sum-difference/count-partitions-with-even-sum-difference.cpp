class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int> s(nums.size(), 0);

        int rightSum = 0;

        for(int i = nums.size() - 1; i>=0; i--){
            rightSum += nums[i];
            s[i] = rightSum;
        }

        int cnt = 0;
        int leftSum = 0;
        
        for(int i  = 0; i < nums.size() - 1; i++){
            leftSum += nums[i];
            int diff = abs(leftSum - s[i+1]);
            if((diff & 1) == 0) cnt++;
        }

        return cnt;

    }
};