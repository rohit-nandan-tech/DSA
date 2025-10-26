class Solution {
public: 
    vector<int> digitCnt = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int backTrack(int n, int curr, int leftDigit){
        if(leftDigit == 0){
            for(int digit = 1; digit <= 9; digit++){
                if(digitCnt[digit] > 0 and digitCnt[digit] < digit)
                    return 0;
            }

            return curr > n ? curr : 0;
        }

        int res = 0;

        for(int digit = 1; digit <= 9; digit++){

            if(digitCnt[digit] > 0 and digitCnt[digit] <= digit){
                digitCnt[digit]--;
                res = backTrack(n, curr * 10 + digit, leftDigit - 1);
                digitCnt[digit]++;
            }

            if(res != 0) break;
        }

        return res;

    }
    int nextBeautifulNumber(int n) {
        int numDigit = to_string(n).size();
        int res = 0;
        for(int i = numDigit; i < INT_MAX;i++){
            res = backTrack(n, 0, i);
            if(res != 0) return res;
        }

        return res;
    }
};