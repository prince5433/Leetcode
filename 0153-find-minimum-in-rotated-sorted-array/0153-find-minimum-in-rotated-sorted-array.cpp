class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;

        // Binary Search lagayenge
        while (lo < hi) {

            // Mid nikal rahe hain
            int mid = lo + (hi - lo) / 2;

            /*
                Intuition:

                Rotated sorted array me minimum element hamesha
                unsorted part me hota hai.

                Example:
                [4,5,6,7,0,1,2]

                mid = 7 , hi = 2

                Agar nums[mid] > nums[hi]
                => minimum right side me hoga
            */
            if (nums[mid] > nums[hi]) {

                // left part discard
                lo = mid + 1;
            }
            else {

                /*
                    Agar nums[mid] <= nums[hi]

                    iska matlab right part sorted hai,
                    to minimum mid pe ya left side me ho sakta hai
                */
                hi = mid;
            }
        }

        /*
            Jab loop khatam hoga,
            lo aur hi dono minimum element par honge
        */
        return nums[lo];
    }
};