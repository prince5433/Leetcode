
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        // Minimum subarray length 1 ho sakti hai.
        int maxi = 1;

        // Current strictly increasing subarray ki length.
        int inclen = 1;

        // Current strictly decreasing subarray ki length.
        int declen = 1;

        // First element se comparison possible nahi hai,
        // isliye second element (index 1) se start karenge.
        for(int i = 1; i < nums.size(); i++) {

            // CASE 1: Current element previous element se bada hai.
            if(nums[i] > nums[i-1]) {

                // Increasing sequence continue ho rahi hai.
                inclen++;

                // Decreasing sequence break ho gayi,
                // isliye uski length reset to 1.
                declen = 1;

            }

            // CASE 2: Current element previous element se chhota hai.
            else if(nums[i] < nums[i-1]) {

                // Decreasing sequence continue ho rahi hai.
                declen++;

                // Increasing sequence break ho gayi.
                inclen = 1;

            }

            // CASE 3: Dono elements equal hain.
            else {

                // Equal elements hone par strictly increasing
                // aur strictly decreasing dono break ho jaati hain.
                inclen = 1;
                declen = 1;
            }

            // Dono lengths mein se maximum lekar
            // overall maximum update karenge.
            maxi = max(maxi, max(inclen, declen));
        }

        return maxi;
    }
};

/*
TIME COMPLEXITY:

1. Loop index 1 se n-1 tak chalega.
   Total iterations = n-1 = O(n).

2. Har iteration mein:
   Comparisons = O(1)
   Increment/reset = O(1)
   Maximum update = O(1)

Final TC = O(n).

SPACE COMPLEXITY:

Sirf 3 variables use kiye hain:
maxi, inclen, declen.

Final SC = O(1).
*/
