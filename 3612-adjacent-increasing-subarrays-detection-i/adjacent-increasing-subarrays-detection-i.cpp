class Solution {
public:
    bool isIncreasing(vector<int>&nums,int start,int k){
        for(int i=start+1 ; i<start+k;i++){
            if(nums[i]<=nums[i-1]){
                return false;
            }
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i+2*k<=n;i++){
            if(isIncreasing(nums,i,k) && isIncreasing(nums,i+k,k)){
                return true;
            }
        }
        return false;
    }
};