class Solution {
public:
    int longestPalindrome(string s) {

        map<char,int> mp;   // har character ki frequency

        // frequency count
        for (char c : s) {
            mp[c]++;
        }

        int ans = 0;
        bool oddFound = false; // check karega kya koi odd freq mila

        // har character ke liye
        for (auto it : mp) {

            if (it.second % 2 == 0) {
                // even frequency → pura use ho sakta hai
                ans += it.second;
            } else {
                // odd frequency → ek kam (even part) use karo
                ans += it.second - 1;
                oddFound = true;
            }
        }

        // agar koi odd frequency thi
        // to center me ek character add kar sakte hain
        if (oddFound) ans += 1;

        return ans;
    }
};
