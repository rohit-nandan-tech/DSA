class Solution {
public:

     int bs(int l, int h, long long num, vector<int>&potions, long long succ){
        long long ans = 0;

        while(l <=h){
            int mid = l + (h - l)/2;

            if(num * potions[mid] >= succ){
                ans += (h -mid +1);
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int>ans(spells.size(), 0);
        long long num = 0;
        for(int i = 0 ;i <spells.size();i++){
            num = bs(0, potions.size() -1, (long long) spells[i], potions, success);
            ans[i] = (int) num;
        }

        return ans;
    }
};