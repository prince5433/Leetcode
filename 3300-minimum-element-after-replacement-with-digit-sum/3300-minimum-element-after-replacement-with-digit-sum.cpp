class Solution {
public:
    int minElement(vector<int>& nums) {

        /*
        Intuition:
        Har number ko replace karna hai
        uske digit sum se.

        Fir minimum digit sum return karna hai.
        */

        vector<int> v;

        for(int n : nums) {

            int s = 0;

            // Calculate digit sum
            while(n) {
                s += n % 10;
                n /= 10;
            }

            // Store digit sum
            v.push_back(s);
        }

        // Smallest digit sum first
        sort(v.begin(), v.end());

        return v[0];
    }
};

/*
---------------- QUICK INTUITION ----------------

Example:

nums = [10, 12, 13]

10 -> 1+0 = 1
12 -> 1+2 = 3
13 -> 1+3 = 4

New array:
[1,3,4]

Minimum = 1

------------------------------------------------

TC:
For each number, digit sum takes O(d)

Total:
O(n*d + nlogn)

d = number of digits

------------------------------------------------

SC:
O(n)

------------------------------------------------

Optimization:

Sorting ki zarurat nahi.

Minimum digit sum directly track kar sakte:

mn = min(mn, digitSum)

TC:
O(n*d)

SC:
O(1)

------------------------------------------------

Pattern:
Math
Digit Manipulation
Simulation
*/