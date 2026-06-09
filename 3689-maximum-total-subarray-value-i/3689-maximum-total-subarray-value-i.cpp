class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        /*
        Intuition:

        Maximum contribution tab milega
        jab largest aur smallest element ka
        difference use kare.

        Difference:
        maxElement - minElement

        Aur ye contribution k times add hoga.
        */

        // Largest element in array
        long long maxi =
            *max_element(nums.begin(), nums.end());

        // Smallest element in array
        long long mini =
            *min_element(nums.begin(), nums.end());

        // Total value
        return (maxi - mini) * 1LL * k;
    }
};

/*
---------------- QUICK INTUITION ----------------

Example:

nums = [2,5,10]
k = 3

max = 10
min = 2

difference = 8

answer = 8 * 3 = 24

------------------------------------------------

Why long long?

(maxi - mini) * k
can exceed int range.

------------------------------------------------

TC:

max_element -> O(n)
min_element -> O(n)

Total:
O(n)

------------------------------------------------

SC:

O(1)

------------------------------------------------

Pattern:

Math
Greedy Observation
Array Processing
*/