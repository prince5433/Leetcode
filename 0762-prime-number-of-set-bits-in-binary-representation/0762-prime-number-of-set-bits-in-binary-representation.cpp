class Solution {
public:

    // Function to check whether a number is prime
    bool isPrime(int n){
        // 0 and 1 are not prime
        if(n <= 1) return false;

        // Check divisibility from 2 up to sqrt(n)
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0)
                return false;   // Not prime
        }
        return true;            // Prime number
    }

    int countPrimeSetBits(int left, int right) {

        int cnt = 0;  // To count numbers whose set bits are prime

        // Iterate from left to right (inclusive)
        for(int i = left; i <= right; i++){

            // __builtin_popcount(i) returns number of set bits (1s) in binary of i
            int setBits = __builtin_popcount(i);

            // Check if number of set bits is prime
            if(isPrime(setBits))
                cnt++;
        }

        // Return final count
        return cnt;
    }
};
