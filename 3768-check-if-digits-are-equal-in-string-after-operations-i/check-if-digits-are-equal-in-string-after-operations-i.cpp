class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2){
            string temp;
            for(int i = 1; i < s.size(); i++){
                int a = s[i-1] - '0';
                int b = s[i] - '0';
                char c = ((a + b)%10) + '0';
                temp.push_back(c);
            }
            s =temp;
        }

        return s[0] == s[1];
    }
};