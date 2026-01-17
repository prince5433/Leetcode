class Solution {
public:
    // checks if all 26 counts are zero
    // if yes => current window is an anagram of p
    bool allZero(vector<int>& count) {
        return count == vector<int>(26, 0);
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int k = p.size();                 // window size = pattern length
        int n = s.size();                 // text length

        vector<int> count(26, 0);         // frequency array for 'a' to 'z'

        // store frequency of pattern p in count[]
        for(char &ch : p) {
            count[ch - 'a']++;
        }

        int i = 0, j = 0;                 // i = window start, j = window end
        int result = 0;                   // (not used, but kept as it is)

        // sliding window over s
        while(j < n) {

            // include s[j] in window => reduce its required frequency
            int idx = s[j] - 'a';
            count[idx]--;

            // when window size becomes exactly k
            if(j - i + 1 == k) {

                // if all counts become zero => anagram found at index i
                if(allZero(count)) {
                    ans.push_back(i);
                }

                // remove outgoing s[i] from window => restore its frequency
                count[s[i] - 'a']++;

                // move window start forward
                i++;
            }

            // move window end forward
            j++;
        }

        return ans;
    }
};
