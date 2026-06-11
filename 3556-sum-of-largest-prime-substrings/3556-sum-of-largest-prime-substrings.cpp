class Solution {
public:

    // Check whether a number is prime
    bool isPrime(long long n) {

        // 0 and 1 are not prime
        if(n <= 1)
            return false;

        /*
        Check divisibility till sqrt(n).

        If any divisor exists,
        number is not prime.
        */
        for(long long i = 2; i * i <= n; i++) {

            if(n % i == 0)
                return false;
        }

        return true;
    }

    long long sumOfLargestPrimes(string s) {

        int n = s.size();

        /*
        Set stores:

        1) Only unique primes
        2) Automatically sorted
        */
        set<long long> primes;

        /*
        Generate every substring.

        i = starting index
        j = ending index
        */
        for(int i = 0; i < n; i++) {

            string curr = "";

            for(int j = i; j < n; j++) {

                // Extend current substring
                curr += s[j];

                // Convert substring to number
                long long num = stoll(curr);

                // Store if prime
                if(isPrime(num))
                    primes.insert(num);
            }
        }

        long long ans = 0;
        int cnt = 0;

        /*
        Traverse from largest prime.

        rbegin() gives largest element first.
        */
        for(auto it = primes.rbegin();
            it != primes.rend() && cnt < 3;
            ++it) {

            ans += *it;
            cnt++;
        }

        return ans;
    }
};

/*
---------------- QUICK INTUITION ----------------

Generate all numeric substrings.

Example:

s = "113"

Substrings:

"1"   -> 1
"11"  -> 11 ✅
"113" -> 113 ✅
"1"   -> 1
"13"  -> 13 ✅
"3"   -> 3 ✅

Unique primes:

{3,11,13,113}

Largest 3:

113 + 13 + 11

Answer = 137

------------------------------------------------

Why Set?

Suppose:

s = "313"

Prime 3 can appear multiple times.

Need distinct primes only.

Set automatically:
- Removes duplicates
- Keeps sorted order

------------------------------------------------

Prime Check:

Instead of checking till n,
check till sqrt(n).

Example:

100

Divisors always appear in pairs.

2 × 50
4 × 25
5 × 20
10 × 10

After sqrt(n),
all factors already checked.

------------------------------------------------

TC:

Substrings:
O(n²)

For each substring:
stoll + prime check

Prime check:
O(√num)

Overall:
O(n² × √num)

------------------------------------------------

SC:

Set stores unique primes.

Worst:
O(number of unique primes)

------------------------------------------------

Pattern:

String Enumeration
Prime Checking
Brute Force
Set
*/