class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;  
            a = temp;
        }
        return a;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;

        for (auto n : nums) {
            st.push_back(n);

            while (st.size() > 1) {
                int a = st.back();
                st.pop_back();
                int b = st.back();
                st.pop_back();

                int g = gcd(a, b);
                if (g > 1) {
                    long long lcm = 1LL * a / g * b;  // compute safely
                    st.push_back((int)lcm);
                } else {
                    st.push_back(b);
                    st.push_back(a);
                    break;
                }
            }
        }

        return st;   // ✅ return the processed stack, not nums
    }
};
