/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return      -1 if num is higher than the picked number
 *               1 if num is lower than the picked number
 *               0 if num is equal to the picked number
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n;     // search space: numbers 1 to n
        int ans = -1;          // correct number store karne ke liye

        while (lo <= hi) {
            // mid calculate kiya overflow se bachne ke liye
            int mid = lo + (hi - lo) / 2;

            // agar mid hi picked number hai
            if (guess(mid) == 0) {
                ans = mid;     // answer mil gaya
                break;         // search yahin stop
            }
            // agar mid picked number se bada hai
            else if (guess(mid) == -1) {
                hi = mid - 1;  // left side search
            }
            // agar mid picked number se chhota hai
            else {
                lo = mid + 1;  // right side search
            }
        }
        return ans;            // final guessed number
    }
};
