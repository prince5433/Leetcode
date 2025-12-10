class Solution {
public:

    // Function to check if a number is prime
    bool isPrime(int n){
        if(n <= 1) return false;           // 0, 1, negative → not prime
        for(int i = 2; i <= sqrt(n); i++){ // check divisors from 2 to sqrt(n)
            if(n % i == 0){                // if any divisor found → not prime
                return false;
            }
        }
        return true;                       // no divisors → prime number
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int fidx = -1, lidx = -1;          // indices of first and last prime
        int n = nums.size();

        // Find first prime from the left
        for(int i = 0; i < n; i++){
            if(isPrime(nums[i])){
                fidx = i;
                break;                     // stop as soon as first prime is found
            }
        }

        // Find first prime from the right (i.e., last prime in array)
        for(int i = n - 1; i >= 0; i--){
            if(isPrime(nums[i])){
                lidx = i;
                break;                     // stop when last prime is found
            }
        }

        // Return absolute difference between first and last prime indices
        return abs(fidx - lidx);
    }
};
