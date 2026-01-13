class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0, hi = letters.size() - 1; 
        char ans = letters[0];   // default answer for wrap-around case

        while (lo <= hi) {
            // mid index calculate kiya (overflow safe)
            int mid = lo + (hi - lo) / 2;

            // agar current letter target se strictly bada hai
            if (letters[mid] > target) {
                ans = letters[mid];   // possible answer store karo
                hi = mid - 1;         // left side me aur better (chhota) answer dhoondo
            } 
            // agar current letter target se chhota ya equal hai
            else {
                lo = mid + 1;         // right side search karo
            }
        }

        // loop ke baad ans me hi next greatest letter hoga
        return ans;
    }
};
