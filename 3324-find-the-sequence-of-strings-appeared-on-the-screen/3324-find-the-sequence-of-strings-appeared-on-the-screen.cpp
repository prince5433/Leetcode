class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;          // stores all intermediate strings
        string curr = "";            // prefix built so far

        // process each character of target
        for (char ch : target) {
            // build strings from 'a' to current character
            for (char c = 'a'; c <= ch; c++) {
                ans.push_back(curr + c); // append new character to prefix
            }
            curr += ch; // lock the current character into the prefix
        }

        return ans; // return the full sequence
    }
};
