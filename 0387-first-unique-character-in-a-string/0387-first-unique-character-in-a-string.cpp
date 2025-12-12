class Solution {
public:
    int firstUniqChar(string s) {

        // Map to store frequency of each character
        map<char, int> mp;

        // 1) Count frequency of all characters
        for (char c : s) {
            mp[c]++;        // increment count of this character
        }

        // 2) Find the first character whose frequency is 1
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] == 1)   // unique character found
                return i;        // return its index
        }

        // 3) If no unique character exists
        return -1;
    }
};
