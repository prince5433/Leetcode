class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // Edge case: agar array empty hai to kuch search hi nahi kar sakte
        if(nums.empty()) return -1;

        int n = nums.size();
        int lo = 0, hi = n - 1;

        /*
        INTUITION:
        Rotated sorted array actually 2 sorted parts hota hai.
        Example:
        [4,5,6,7,0,1,2]

        Left sorted part  = [4,5,6,7]
        Right sorted part = [0,1,2]

        Hume pehle pivot (smallest element) dhundhna hai,
        kyunki wahi rotation point hai.
        Pivot mil gaya -> decide karenge target kis sorted half me hai.
        Then normal binary search.
        */

        // ---------------- STEP 1: FIND PIVOT ----------------
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;  // overflow safe mid

            /*
            Core thought:
            nums[hi] se compare karenge.

            Agar nums[mid] > nums[hi]:
            matlab mid left sorted part me hai
            aur pivot right side me hoga.

            Example:
            [4,5,6,7,0,1,2]
                     ^
                    mid = 7
            hi = 2

            7 > 2 => pivot right side
            */
            if (nums[mid] > nums[hi])
                lo = mid + 1;

            /*
            Else:
            nums[mid] <= nums[hi]
            matlab pivot left side me ho sakta hai
            (including mid)
            */
            else
                hi = mid;
        }

        // lo == hi => smallest element mil gaya => pivot
        int pivot = lo;

        // Full range reset kar rahe because ab actual target search karna hai
        lo = 0;
        hi = n - 1;

        // ---------------- STEP 2: DECIDE CORRECT HALF ----------------
        /*
        Ab target kis sorted half me ho sakta hai?

        Right half range:
        nums[pivot] ... nums[n-1]

        Agar target is range me hai:
        right side search karo.
        Warna left side.
        */
        if (target >= nums[pivot] && target <= nums[hi])
            lo = pivot;
        else
            hi = pivot - 1;

        // ---------------- STEP 3: NORMAL BINARY SEARCH ----------------
        /*
        Ab selected half guaranteed sorted hai.
        So standard binary search.
        */
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            // Target mil gaya
            if (nums[mid] == target)
                return mid;

            // Target bigger -> right side
            else if (nums[mid] < target)
                lo = mid + 1;

            // Target smaller -> left side
            else
                hi = mid - 1;
        }

        // Nahi mila
        return -1;
    }
};

/*
------------------- DEEP INTUITION -------------------

Is problem ka trick:
Rotated array ko unsorted mat samjho.
Ye bas 2 sorted arrays ka combination hai.

Example:
[4,5,6,7,0,1,2]

Bas break-point (pivot) dhundho.
Fir correct sorted half me normal binary search.

Ye "Binary Search on Answer Region" type thinking hai.

------------------------------------------------------

TC (Time Complexity):
Pivot find     -> O(log n)
Binary search  -> O(log n)

Total:
O(log n) + O(log n)
= O(log n)

Best / Avg / Worst:
O(log n)

------------------------------------------------------

SC (Space Complexity):
Only few variables:
lo, hi, mid, pivot, n

No extra array / stack / recursion.

SC = O(1)

------------------------------------------------------

Pattern:
Binary Search
Rotated Sorted Array
Pivot Finding
Divide & Conquer
*/