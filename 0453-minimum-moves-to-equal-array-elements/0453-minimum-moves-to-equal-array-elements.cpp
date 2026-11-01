class Solution {
public:
    int minMoves(vector<int>& nums) {

        // Step 1: Array ka minimum element find karo.
        // Humein ultimately sabhi elements ko isi minimum value
        // ke equal banana hai.
        int mini = *min_element(nums.begin(), nums.end());

        // Total operations count karne ke liye.
        int moves = 0;

        // Step 2: Har element ko minimum element se compare karo.
        for (int num : nums) {

            // Current element ko minimum tak reduce karne ke liye
            // jitna difference hai, utne moves required honge.
            //
            // Example: num = 5, mini = 2
            // Difference = 5 - 2 = 3 moves.
            moves += num - mini;
        }

        // Sabhi elements ke differences ka sum
        // minimum required moves represent karta hai.
        return moves;
    }
};

/*
TIME COMPLEXITY: O(N)
Minimum find karne mein O(N) aur sum calculate karne mein O(N).

SPACE COMPLEXITY: O(1)
Sirf constant extra variables use ho rahe hain.
*/