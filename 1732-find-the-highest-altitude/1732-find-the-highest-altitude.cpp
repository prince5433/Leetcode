class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        /*
        Intuition:

        Initial altitude = 0

        gain[i] tells change in altitude
        between two points.

        Keep building current altitude
        and track maximum altitude reached.
        */

        int ans = 0;

        int n = gain.size();

        /*
        Current altitude.

        Starts from 0.
        */
        int cal = 0;

        for(int i = 0; i < n; i++) {

            // Update current altitude
            cal += gain[i];

            // Track maximum altitude seen
            ans = max(ans, cal);
        }

        return ans;
    }
};

/*
---------------- QUICK INTUITION ----------------

Example:

gain = [-5,1,5,0,-7]

Start:

Altitude = 0

--------------------------------

After -5:

Altitude = -5

Max = 0

--------------------------------

After +1:

Altitude = -4

Max = 0

--------------------------------

After +5:

Altitude = 1

Max = 1

--------------------------------

After 0:

Altitude = 1

Max = 1

--------------------------------

After -7:

Altitude = -6

Max = 1

Answer = 1

------------------------------------------------

Why ans starts from 0?

Problem says:

Initial altitude = 0

Even if all gains are negative,
highest altitude can still be 0.

Example:

gain = [-4,-3]

Altitudes:

0, -4, -7

Answer = 0

------------------------------------------------

Note:

int maxal = INT_MIN;

Ye variable unused hai,
remove kar sakte ho.

------------------------------------------------

TC:

O(n)

------------------------------------------------

SC:

O(1)

------------------------------------------------

Pattern:

Prefix Sum
Running Sum
Array Traversal
*/