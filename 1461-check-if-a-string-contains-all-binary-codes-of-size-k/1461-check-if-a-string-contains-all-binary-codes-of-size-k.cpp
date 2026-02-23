class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int n = s.size();  // length of given string
        
        set<string> st;    // set to store unique substrings of length k
        
        // Sliding window: generate all substrings of size k
        for(int i = 0; i <= n - k; i++){
            st.insert(s.substr(i, k));  // extract substring of length k and insert into set
        }
        
        // Total possible binary strings of length k = 2^k
        // If set size equals 2^k, then all possible binary codes exist
        return (st.size() == (1 << k));
    }
};