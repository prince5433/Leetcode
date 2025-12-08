class Solution {
public:
    int largestPrime(int n) {

        // Edge case: smallest prime is 2
        if(n < 2) return 0;

        // Sieve of Eratosthenes to mark prime numbers
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i * i <= n; i++){
            if(isPrime[i]){ // if i is prime, mark all multiples as not prime
                for(int j = i * i; j <= n; j += i){
                    isPrime[j] = false;
                }
            }
        }

        // Store only prime numbers in the vector
        vector<int> primes;
        for(int i = 2; i <= n; i++){
            if(isPrime[i]) primes.push_back(i);
        }

        // Build sum of consecutive primes starting from 2
        long long sum = 0;
        int ans = 0;

        for(int p : primes){
            sum += p;
            if(sum > n) break;        // if sum exceeds n, stop
            if(isPrime[sum]) ans = sum; // if sum is prime, update result
        }

        return ans;
    }
};
