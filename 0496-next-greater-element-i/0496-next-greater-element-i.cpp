class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> mp; // har element ka next greater store karega
        stack<int> st;             // monotonic decreasing stack

        // nums2 ko process kar rahe hain
        for (int x : nums2) {

            // jab current element stack ke top se bada ho
            // to stack ke top ka next greater current element hoga
            while (!st.empty() && x > st.top()) {
                mp[st.top()] = x;  // mapping store
                st.pop();
            }

            // current element ko stack me daal do
            st.push(x);
        }

        // jo elements stack me reh gaye
        // unka koi next greater nahi hai
        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        // nums1 ke liye answer banao
        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};
