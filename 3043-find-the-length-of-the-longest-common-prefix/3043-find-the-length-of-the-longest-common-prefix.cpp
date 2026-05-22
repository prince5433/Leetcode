class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        /*
        Intuition:
        Prefix means starting digits same.

        Example:
        12345 and 12389
        common prefix = 123 (len = 3)

        Trick:
        x /= 10 -> rightmost digit remove hoti hai,
        aur saare prefixes mil jate.
        */

        set<int> st;

        // Store all prefixes of arr1
        for (int x : arr1) {
            while (x) {
                st.insert(x);   // current prefix
                x /= 10;        // shorten prefix
            }
        }

        int ans = 0;

        // Check prefixes of arr2
        for (int x : arr2) {
            while (x) {

                // If prefix exists in arr1
                if (st.count(x)) {
                    ans = max(ans, (int)to_string(x).size());
                }

                x /= 10;
            }
        }

        return ans;
    }
};

/*
Quick Idea:
Store all prefixes of arr1 in set.
Then generate prefixes of arr2 and check match.
Longest matching prefix length = answer.

TC:
Let D = max digits (~10)
set insert/find = logN

O((n + m) * D * logN)

SC:
Set stores prefixes
O(n * D)

Optimization:
unordered_set -> avg O(1) lookup
Better TC: O((n+m)*D)
*/