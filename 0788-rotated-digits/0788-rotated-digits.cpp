class Solution {
public:

    // This function checks whether a number becomes a valid and different number after rotation
    bool isGood(int n) {
        bool good = false;   // this will become true if we find at least one digit from {2,5,6,9}

        while (n > 0) {
            int d = n % 10;   // take last digit

            // digits 3,4,7 become invalid after rotation
            if (d == 3 || d == 4 || d == 7) return false;

            // digits 2,5,6,9 change to another valid digit after rotation
            // so number has potential to become a "good" number
            if (d == 2 || d == 5 || d == 6 || d == 9) {
                good = true;
            }

            n /= 10;   // remove last digit
        }

        // return true only if:
        // 1. no invalid digit was found
        // 2. at least one digit actually changes after rotation
        return good;
    }

    int rotatedDigits(int n) {
        int cnt = 0;   // stores total good numbers from 1 to n

        // check every number one by one
        for (int i = 1; i <= n; i++) {
            if (isGood(i)) cnt++;
        }

        return cnt;
    }
};