// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n;          // search space: versions 1 to n

        while (lo <= hi) {
            // mid calculate kiya to avoid integer overflow
            int mid = lo + (hi - lo) / 2;

            // agar mid bad version hai
            if (isBadVersion(mid)) {
                // first bad left side me bhi ho sakta hai
                hi = mid - 1;
            } 
            // agar mid good version hai
            else {
                // first bad right side me hoga
                lo = mid + 1;
            }
        }

        // loop ke end par lo hi first bad version ko point karta hai
        return lo;
    }
};
