class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumMax(nums) - sumMin(nums);
    }

    long long sumMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<pair<int,int>> st;

        // Previous Smaller
        for(int i = 0; i < n; i++) {
            int count = 1;
            while(!st.empty() && st.top().first > arr[i]) {
                count += st.top().second;
                st.pop();
            }
            st.push({arr[i], count});
            left[i] = count;
        }

        while(!st.empty()) st.pop();

        // Next Smaller
        for(int i = n-1; i >= 0; i--) {
            int count = 1;
            while(!st.empty() && st.top().first >= arr[i]) {
                count += st.top().second;
                st.pop();
            }
            st.push({arr[i], count});
            right[i] = count;
        }

        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += (long long)arr[i] * left[i] * right[i];
        }

        return sum;
    }

    long long sumMax(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<pair<int,int>> st;

        // Previous Greater
        for(int i = 0; i < n; i++) {
            int count = 1;
            while(!st.empty() && st.top().first < arr[i]) {
                count += st.top().second;
                st.pop();
            }
            st.push({arr[i], count});
            left[i] = count;
        }

        while(!st.empty()) st.pop();

        // Next Greater
        for(int i = n-1; i >= 0; i--) {
            int count = 1;
            while(!st.empty() && st.top().first <= arr[i]) {
                count += st.top().second;
                st.pop();
            }
            st.push({arr[i], count});
            right[i] = count;
        }

        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += (long long)arr[i] * left[i] * right[i];
        }

        return sum;
    }
};