class Solution {
public:
 
    int canBeTypedWords(string s, string brokenLetters) {
        unordered_set<char>st;

        for(auto c: brokenLetters){
            st.insert(c);
        }

        bool canTake = true;
        int cnt = 0;

        for(int i = 0 ; i<s.size();i++){
            if((st.find(s[i]) != st.end())){
                canTake = false;
            }

            if(s[i] == ' ' || i ==s.size() - 1){
                if(canTake) cnt++;
                else canTake = true;
            }
            
        }

        return cnt;
        
    }
};