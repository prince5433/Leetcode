class Solution {
public:
    vector<vector<int>> ans;   // final answer: saari permutations store hongi
    int n;                     // nums ka size
    unordered_set<int> st;     // current permutation me kaunse elements use ho chuke hain

    void solve(vector<int>& temp, vector<int>& nums) {

        // Base case:
        // agar temp ka size nums ke size ke barabar ho gaya
        // matlab ek complete permutation ban chuki hai
        if (temp.size() == n) {
            ans.push_back(temp);   // permutation ko answer me daal do
            return;
        }

        // har index par try karte hain ki kaunsa element next add kare
        for (int i = 0; i < n; i++) {

            // agar nums[i] pehle se use nahi hua hai
            if (st.find(nums[i]) == st.end()) {

                // choose
                temp.push_back(nums[i]);  // element ko permutation me add karo
                st.insert(nums[i]);       // mark karo ki ye element use ho chuka hai

                // explore
                solve(temp, nums);        // recursion se aage ki positions fill karo

                // un-choose (backtracking)
                temp.pop_back();          // last element hatao
                st.erase(nums[i]);        // element ko unused mark karo
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();        // nums ka size store kar liya
        vector<int> temp;      // temporary vector jo current permutation banayega
        solve(temp, nums);     // backtracking start
        return ans;            // saari permutations return
    }
};
