class Solution {
public:
    bool check(vector<int>& nums) {
        
        int n = nums.size();
        int pvt = -1;

        /*
        Intuition:
        Check if array was originally sorted
        and then rotated.

        Rotated sorted array me sirf 1 "drop" hota hai
        where nums[i] > nums[i+1]
        */

        // Find pivot (drop point)
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                pvt = i;
            }
        }

        // Already sorted
        if (pvt == -1) return true;

        /*
        Reverse logic:
        Rotation undo karne ki try.
        Example:
        [3,4,5,1,2]
        pivot = 2

        Reverse left + right + whole
        => original sorted array
        */

        reverse(nums.begin(), nums.begin() + pvt + 1);
        reverse(nums.begin() + pvt + 1, nums.end());
        reverse(nums.begin(), nums.end());

        // Check if sorted
        bool flag = true;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1])
                flag = false;
        }

        return flag;
    }
};

/*
Quick Idea:
Find pivot where order breaks.
Undo rotation using reverse.
Then check if sorted.

Example:
[3,4,5,1,2]
-> reverse back
-> [1,2,3,4,5]
=> true

TC:
Pivot find   -> O(n)
3 reverse    -> O(n)
Check sorted -> O(n)

Total = O(n)

SC:
O(1)

Optimization:
Reverse ki zarurat nahi.
Bas count drops.

If count of nums[i] > nums[i+1] <= 1
and last <= first
then true.
Cleaner O(n), no modification.
*/