class Solution {
public:
    int minLights(vector<int>& lights) {

        /*
        Intuition:

        Some positions are already illuminated
        by existing bulbs.

        First find which positions are lit.

        Then for every dark position,
        place a new bulb greedily.

        One new bulb can cover:

        i, i+1, i+2

        So skip next 3 positions.
        */

        int n = lights.size();

        /*
        Difference Array

        Used to mark ranges illuminated
        by existing bulbs efficiently.
        */
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; i++) {

            if (lights[i] > 0) {

                /*
                Current bulb illuminates:

                [i-radius , i+radius]
                */
                int left = max(0, i - lights[i]);

                int right = min(n - 1, i + lights[i]);

                diff[left]++;

                diff[right + 1]--;
            }
        }

        /*
        isilluminated[i] tells whether
        position i already has light.
        */
        vector<bool> isilluminated(n, false);

        int curr = 0;

        for (int i = 0; i < n; i++) {

            curr += diff[i];

            if (curr > 0)
                isilluminated[i] = true;
        }

        int newbulbs = 0;

        /*
        Greedy:

        Whenever dark position found,
        place one new bulb.

        It covers current position
        and next two positions.
        */
        for (int i = 0; i < n;) {

            if (!isilluminated[i]) {

                newbulbs++;

                // Covered by new bulb
                i += 3;
            } else {

                i++;
            }
        }

        return newbulbs;
    }
};

/*
---------------- QUICK INTUITION ----------------

Step 1:

Find all positions already illuminated.

Use Difference Array
instead of marking each range manually.

------------------------------------------------

Example:

lights = [0,1,0,0,0]

Bulb at index 1

Radius = 1

Covers:

[0,2]

Illuminated:

T T T F F

------------------------------------------------

Step 2:

Dark positions:

Index 3
Index 4

Place new bulb at 3.

It covers:

3,4,5

So both become covered.

Answer = 1

------------------------------------------------

Difference Array Idea

Range [L,R]

diff[L]++

diff[R+1]--

Later prefix sum gives
how many bulbs cover each position.

------------------------------------------------

Dry Run

lights:

[0,0,0,0,0]

No existing bulbs.

Illuminated:

F F F F F

--------------------------------

i = 0

Dark

Place bulb

count = 1

Jump to i = 3

--------------------------------

i = 3

Dark

Place bulb

count = 2

Jump to i = 6

Stop.

Answer = 2

------------------------------------------------

TC

Building Difference Array:
O(n)

Prefix Sum:
O(n)

Greedy Traversal:
O(n)

Total:
O(n)

------------------------------------------------

SC

diff:
O(n)

isilluminated:
O(n)

Total:
O(n)

------------------------------------------------

Pattern

Difference Array
Prefix Sum
Greedy
Range Coverage
*/