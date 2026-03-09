class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string t = s;
        sort(t.begin(), t.end()); // Target sorted string

        // Case 0: Pehle se sorted hai toh mehnat kyun karein?
        if (s == t) return 0;

        // Case 1: Length 2 par constraint (not entire string) ki wajah se
        // hum sirf length 1 ke substrings sort kar sakte hain, jo kuch badlega nahi.
        if (n == 2) return -1;

        // Case 2: 1 Operation
        // Agar pehla ya aakhri element sahi jagah par hai, 
        // toh baaki bache huye n-1 elements ko ek baar mein sort kar do.
        if (s[0] == t[0] || s[n - 1] == t[n - 1]) return 1;

        // Case 3: 2 Operations
        // Logic: Kya hum minimum element ko front pe la sakte hain?
        // Haan, agar wo last index ke pehle kahin bhi ho (Proper Prefix).
        bool minInProperPrefix = false;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == t[0]) minInProperPrefix = true;
        }

        // Logic: Kya hum maximum element ko end mein bhej sakte hain?
        // Haan, agar wo index 0 ke baad kahin bhi ho (Proper Suffix).
        bool maxInProperSuffix = false;
        for (int i = 1; i < n; i++) {
            if (s[i] == t[n - 1]) maxInProperSuffix = true;
        }

        // Agar dono mein se ek bhi condition true hai, toh 2 operations kaafi hain.
        if (minInProperPrefix || maxInProperSuffix) return 2;

        // Case 4: 3 Operations
        // Ye tab hota hai jab saare min elements last mein hon 
        // aur saare max elements start mein (Worst Case).
        return 3;
    }
};