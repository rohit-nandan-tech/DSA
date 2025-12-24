class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& cap) {
        int sum = 0;

        for(auto a: apple){
            sum+=a;
        }

        sort(cap.begin(), cap.end());
        int cnt = 0;
        for(int i = cap.size() - 1 ; i >= 0; i--){
            sum-=cap[i];
            cnt++;
            if(sum <= 0) return cnt;
        }
        return cnt;
    }
};