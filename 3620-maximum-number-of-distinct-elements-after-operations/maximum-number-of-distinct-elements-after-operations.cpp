class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int distinct = 0,  demand = INT_MIN;

        for(auto n: nums){

            int lowerRange = n-k;
            int upperRange = n + k;
            if(demand < lowerRange){
                distinct++;
                demand = lowerRange;
            }
            else if(demand < upperRange){
                distinct++;
                demand++;
            }
        }

        return distinct;
    }
};