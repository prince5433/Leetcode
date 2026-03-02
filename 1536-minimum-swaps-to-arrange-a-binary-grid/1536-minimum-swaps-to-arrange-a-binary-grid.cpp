class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {

        /*
        INTUITION:

        Hume grid ko aise arrange karna hai ki main diagonal ke upar
        (i.e., column j > i) sab elements 0 ho.

        Iska matlab:
        Row i ko kam se kam (n - 1 - i) trailing zeros chahiye.

        Kyun trailing zeros?
        Kyuki diagonal ke right side wale elements hi upper triangle hote hain,
        aur wo row ke end me hi hote hain.

        Approach (Greedy):
        1. Har row ke trailing zeros count karo.
        2. Row i ke liye required = n - 1 - i.
        3. Agar current row satisfy nahi karti,
           neeche search karo valid row.
        4. Us row ko adjacent swaps se upar lao.
        5. Agar koi valid row hi na mile → return -1.

        Ye greedy isliye sahi hai kyuki har position pe
        minimum distance wala valid row choose karna optimal hai.
        */

        int n = grid.size();
        vector<int> tz(n);

        // Step 1: Count trailing zeros per row
        for(int i = 0; i < n; i++) {

            int zeroes = 0;

            for(int j = n - 1; j >= 0; j--) {
                if(grid[i][j] == 0)
                    zeroes++;
                else
                    break;
            }

            tz[i] = zeroes;
        }

        int swaps = 0;

        // Step 2: Arrange rows greedily
        for(int i = 0; i < n; i++) {

            int required = n - 1 - i;
            int j = i;

            // Find first row satisfying requirement
            while(j < n && tz[j] < required) {
                j++;
            }

            // If not found → impossible
            if(j == n)
                return -1;

            // Bubble row up to correct position
            while(j > i) {
                swap(tz[j], tz[j - 1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};