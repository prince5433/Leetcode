class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        // Har element ka Next Greater Element store karenge.
        // Agar nahi mila, toh -1 hi rahega.
        vector<int> nge(n, -1);

        // Stack mein direct elements store karenge, indices nahi.
        stack<int> st;

        // Circular array hai, isliye 2 baar traverse karenge.
        for(int i = 2*n-1; i >= 0; i--) {

            // Circular traversal ke liye modulo use karenge.
            int idx = i % n;

            // Current element se chhote ya equal elements
            // next greater nahi ban sakte, isliye pop kar do.
            while(!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }

            // Answer sirf first traversal mein calculate karenge.
            if(i < n) {
                if(!st.empty()) {
                    nge[idx] = st.top();
                }
            }

            // Current element ko stack mein push karo.
            st.push(nums[idx]);
        }

        return nge;
    }
};