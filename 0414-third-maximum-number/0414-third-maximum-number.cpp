class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end()); // duplicates remove + sorted store hota hai (ascending)

        if (st.size() < 3) return *st.rbegin(); // agar 3 unique elements nahi hai to max return karo

        auto it = st.rbegin(); // reverse iterator -> largest element
        it++;                  // 2nd largest
        it++;                  // 3rd largest

        return *it; // third maximum return
    }
};
