class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int> st;


        for(int i = 0; i < nums2.size(); i++){
            while(!st.empty() and st.top() < nums2[i]){
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        vector<int>ans;
        for(auto n: nums1){
            if(mp.find(n) != mp.end()) ans.push_back(mp[n]);
            else ans.push_back(-1);
        }
        return ans;
    }
};