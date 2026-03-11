class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        set<int> st;                // stores unique cards in current window
        int i = 0, j = 0;           // two pointers
        int ans = INT_MAX;          // store minimum length
        int n = cards.size();

        while (j < n) {

            // if duplicate card found
            while (st.count(cards[j])) {
                ans = min(ans, j - i + 1);  // update minimum window length
                st.erase(cards[i]);         // remove leftmost card
                i++;                        // shrink window from left
            }

            st.insert(cards[j]);            // add current card to set
            j++;                            // expand window
        }

        // if no duplicate found return -1
        return ans == INT_MAX ? -1 : ans;
    }
};