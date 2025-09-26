class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cnt = 0, n = nums.size() ;

        sort(nums.begin(), nums.end());

        for(int k = n - 1; k >= 2; k--){
            int i = 0, j = k - 1;

            while(i < j ){
                if(nums[i] +  nums[j] >  nums[k]){
                    cnt+= 1+ (j - i - 1);
                    j--;
                }
                else
                    i++;
            }
        }

        return cnt;
    }
};