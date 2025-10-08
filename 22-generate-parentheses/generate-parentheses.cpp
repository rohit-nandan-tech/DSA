class Solution {
public:
    void rec(string s, int open, int close, vector<string>&ans, int n){
        if(s.size() == 2 * n){
            ans.push_back(s);
            return;
        }

        if(open < n){
            rec(s + '(', open +1, close, ans, n);
        }

        if(close < open){
            rec(s+')', open, close + 1 , ans, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        rec("", 0, 0, ans, n);
        return ans;
    }
};