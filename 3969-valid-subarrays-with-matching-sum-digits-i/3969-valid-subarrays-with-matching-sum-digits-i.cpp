class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {

        /*
        Intuition:

        For every subarray,

        1. Find its sum.
        2. Last digit of sum must be x.
        3. First digit of sum must also be x.

        If both conditions satisfy,
        count this subarray.
        */

        int n = nums.size();

        int valid = 0;

        // Try every starting index
        for (int i = 0; i < n; i++) {

            long long csum = 0;

            // Extend subarray till j
            for (int j = i; j < n; j++) {

                csum += nums[j];

                /*
                Last digit check.

                Example:

                123 % 10 = 3
                */
                if (csum % 10 == x) {

                    long long temp = csum;

                    /*
                    Extract first digit.

                    Example:

                    1234

                    1234 -> 123
                    123  -> 12
                    12   -> 1
                    */
                    while (temp >= 10) {
                        temp /= 10;
                    }

                    /*
                    First digit == x
                    */
                    if (temp == x) {
                        valid++;
                    }
                }
            }
        }

        return valid;
    }
};

/*
---------------- QUICK INTUITION ----------------

Valid Subarray:

First digit of subarray sum = x

AND

Last digit of subarray sum = x

------------------------------------------------

Example:

nums = [5,2,3]

x = 5

--------------------------------

Subarray:

[5]

sum = 5

First digit = 5

Last digit = 5

Valid ✅

--------------------------------

Subarray:

[5,2]

sum = 7

First digit = 7

Last digit = 7

Not Valid ❌

--------------------------------

Subarray:

[5,2,3]

sum = 10

First digit = 1

Last digit = 0

Not Valid ❌

Answer = 1

------------------------------------------------

How First Digit Is Found?

Example:

sum = 5678

Keep dividing by 10:

5678
567
56
5

First digit = 5

------------------------------------------------

Dry Run

nums = [5,5]

x = 5

i = 0

j = 0

sum = 5

First = 5
Last = 5

count = 1

--------------------------------

j = 1

sum = 10

First = 1
Last = 0

Not counted

--------------------------------

i = 1

j = 1

sum = 5

Count = 2

------------------------------------------------

TC

Outer Loop:
O(n)

Inner Loop:
O(n)

First digit extraction:
O(log(sum))

Total:

O(n² · log(sum))

------------------------------------------------

SC

Only variables used.

O(1)

------------------------------------------------

Pattern

Brute Force
Subarray Enumeration
Digit Manipulation

------------------------------------------------

Optimization

Current solution checks
every subarray.

If constraints are large,
O(n²) may TLE.

This is a brute-force approach.
*/