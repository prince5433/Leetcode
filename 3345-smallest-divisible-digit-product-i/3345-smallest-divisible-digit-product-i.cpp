class Solution {
public:
    // Function to calculate product of digits of a number
    int product(int n){
        int prod = 1;              // Initialize product as 1
        while(n > 0){
            int digit = n % 10;    // Get last digit
            prod *= digit;         // Multiply with product
            n /= 10;               // Remove last digit
        }
        return prod;               // Return digit product
    }

    // Function to find the smallest number >= n
    // whose digit product is divisible by t
    int smallestNumber(int n, int t) {
        int i = n;
        while(true){
            int prod = product(i);   // Get product of digits
            if(prod % t == 0) {       // Check divisibility
                return i;             // Return answer
            }
            i++;                      // Try next number
        }
    }
};
