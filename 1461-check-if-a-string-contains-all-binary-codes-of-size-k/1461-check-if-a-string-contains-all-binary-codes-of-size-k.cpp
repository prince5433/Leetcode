class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        // Intuition:
        // A binary string of length k can have total 2^k different combinations.
        // Example: k = 2 → "00", "01", "10", "11"
        // We slide a window of size k over string s and store all substrings.
        // If the number of unique substrings equals 2^k, then all binary codes exist.

        int n = s.size();   // length of the given string
        
        set<string> st;     // set automatically keeps only unique substrings
        
        // Sliding window to generate all substrings of length k
        for(int i = 0; i <= n - k; i++){
            
            // substr(i, k) → substring starting from index i of length k
            // Example: s = "001101", k = 2
            // substrings: "00", "01", "11", "10", "01"
            
            st.insert(s.substr(i, k));   // store substring in set
        }
        
        // Total possible binary strings of length k = 2^k
        // If we have collected exactly 2^k unique substrings,
        // then every possible binary code of length k exists in s
        
        return (st.size() == (1 << k));  // (1 << k) = 2^k
    }
};