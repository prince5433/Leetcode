
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        // Answer bahut bada ho sakta hai,
        // isliye modulo 10^9 + 7 use karenge.
        long long MOD = 1e9 + 7;

        long long n = arr.size();

        // STEP 1: PREFIX SUM ARRAY
        //
        // pre[i] = arr[0] se arr[i] tak ka sum.
        //
        // Example:
        // arr = [1, 2, 3]
        // pre = [1, 3, 6]

        vector<long long> pre(n);

        // First element ka prefix sum wahi element hoga.
        pre[0] = arr[0];

        // Har index ka prefix sum calculate karo.
        for(long long i = 1; i < n; i++) {

            // Previous prefix sum + current element.
            pre[i] = pre[i - 1] + arr[i];
        }
        // TC = O(n).


        // STEP 2: COUNT ODD AND EVEN PREFIX SUMS

        // Initially koi odd prefix sum nahi mila.
        long long odd = 0;

        // Empty prefix sum = 0.
        // Zero is even, isliye initially even = 1.
        //
        // Ye empty prefix subarrays ko index 0 se start
        // karne mein help karta hai.
        long long even = 1;

        // Total subarrays having odd sum.
        long long result = 0;


        // STEP 3: TRAVERSE ALL PREFIX SUMS

        for(long long num : pre) {

            // CASE 1: Current prefix sum is EVEN.
            if(num % 2 == 0) {

                // Previous odd prefix sums ke saath
                // current subarray ka sum odd hoga.
                //
                // Odd + Even = Odd.
                result += odd;

                // Current even prefix sum ko count karo.
                even++;
            }

            // CASE 2: Current prefix sum is ODD.
            else {

                // Previous even prefix sums ke saath
                // current subarray ka sum odd hoga.
                //
                // Odd + Even = Odd.
                result += even;

                // Current odd prefix sum ko count karo.
                odd++;
            }

            // Answer ko modulo ke andar maintain karo.
            result %= MOD;
        }
        // Loop runs n times.
        // Each iteration O(1).
        // TC = O(n).

        return result;
    }
};

/*
TIME COMPLEXITY:

1. Prefix Sum construction:
   O(n)

2. Prefix Sum traversal:
   O(n)

Total TC = O(n) + O(n) = O(n).


SPACE COMPLEXITY:

1. Prefix Sum array:
   O(n)

2. odd, even, result:
   O(1)

Total SC = O(n).
*/
