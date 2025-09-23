class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n = version1.size(), m = version2.size();

        while(i < n || j < m){
            long num1 = 0, num2 = 0;

            // version1 se ek block number nikal lo
            while(i < n && version1[i] != '.'){
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            i++; // dot skip karo

            // version2 se ek block number nikal lo
            while(j < m && version2[j] != '.'){
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            j++; // dot skip karo

            // compare karo
            if(num1 > num2) return 1;
            if(num1 < num2) return -1;
        }

        return 0;
    }
};
