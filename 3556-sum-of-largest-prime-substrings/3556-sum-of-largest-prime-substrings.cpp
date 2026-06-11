class Solution {
public:
    bool isPrime(long long n) {
        if(n <= 1) return false;
        for(long long i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        int n = s.size();

        set<long long> primes;

        for(int i = 0; i < n; i++) {
            string curr = "";

            for(int j = i; j < n; j++) {
                curr += s[j];

                long long num = stoll(curr);

                if(isPrime(num))
                    primes.insert(num);
            }
        }

        long long ans = 0;
        int cnt = 0;

        for(auto it = primes.rbegin(); it != primes.rend() && cnt < 3; ++it) {
            ans += *it;
            cnt++;
        }

        return ans;
    }
};