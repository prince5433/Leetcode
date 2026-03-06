class Solution {
public:
    bool checkOnesSegment(string s) {

        // find("01") string me "01" pattern search karta hai
        // agar nahi milta to string::npos return hota hai

        // agar "01" exist karta hai → matlab 1 ka segment khatam ho gaya
        // aur baad me 1 aa sakta hai → multiple segments possible

        // agar "01" nahi hai → matlab saare 1 ek hi continuous block me hain

        return s.find("01") == string::npos;
    }
};