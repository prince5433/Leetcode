class Solution {
public:
    #define ll long long

    // Function to check if a number is prime
    bool isPrime(int n) {
        if (n <= 1) return false;         // 0,1 are not prime
        if (n <= 3) return true;          // 2 and 3 are prime
        if (n % 2 == 0 || n % 3 == 0)     // eliminate multiples of 2 and 3
            return false;

        // Check only numbers of form 6k ± 2
        for (ll i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }

    // Function to check if num is a "complete prime"
    bool completePrime(int num) {

        string s = to_string(num);   // convert number → string for substring extraction
        int n = s.size();

        // Check all prefix substrings: 2, 23, 233, ...
        for (int i = 0; i < n; i++) {
            int x = stoi(s.substr(0, i + 1));   // prefix from index 0 to i
            if (!isPrime(x)) return false;      // if any prefix is not prime → not complete prime
        }

        // Check all suffix substrings: 233, 33, 3
        for (int i = 0; i < n; i++) {
            int y = stoi(s.substr(i));          // suffix from index i to end
            if (!isPrime(y)) return false;      // if any suffix is not prime → not complete prime
        }

        return true;   // all prefixes & suffixes prime → number is complete prime
    }
};
