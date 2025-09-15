class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int s) {
        if(s==0) return {-1};
        int i = 0;
        int j = i+1;
        long long sum = arr[i];
        int n = arr.size();
        while(i<=j&&j<n)
        {
            if(sum>s)
            {
                while(i<n && sum>s)
                {
                    sum = sum-arr[i];
                    i++;
                }
            }
            else if(sum==s) break;
            
            else{sum +=arr[j];
            j++;}
            
        }
// a last if condition outside the loop because after the addition of the last digit the sum may have become greater than s
        if(sum>s)
        {
        while( i<n && sum>s)
            {
                sum = sum-arr[i];
                i++;
            }
        }
//checking if sum is not equal to s return -1
        if(sum!=s ) return {-1};
        return {i+1,j};
    }
};