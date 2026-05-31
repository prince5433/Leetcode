class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        /*
        Intuition:
        Chhote asteroids pehle destroy karna best hai.

        Kyunki asteroid destroy karne ke baad
        mass increase ho jata hai.

        So greedy approach:
        Sort asteroids in increasing order.
        */

        sort(asteroids.begin(), asteroids.end());

        int n = asteroids.size();

        /*
        long long use kiya because
        mass bahut bada ho sakta hai
        after multiple additions.
        */
        long long curr = mass;

        // Process asteroids from smallest to largest
        for(int ast : asteroids) {

            /*
            Current mass asteroid se chhota hai
            to destroy nahi kar sakte.
            */
            if(curr < ast) {
                return false;
            }

            /*
            Asteroid destroy ho gaya.

            New mass:
            current mass + asteroid mass
            */
            curr += ast;
        }

        // Sab asteroids destroy ho gaye
        return true;
    }
};

/*
---------------- QUICK INTUITION ----------------

Example:

mass = 10

asteroids = [3,9,19,5]

Sort:

[3,5,9,19]

Start:
curr = 10

10 >= 3
curr = 13

13 >= 5
curr = 18

18 >= 9
curr = 27

27 >= 19
curr = 46

All destroyed -> true

------------------------------------------------

Why Sorting?

Agar bada asteroid pehle aagaya,
ho sakta hai destroy hi na kar pao.

Small asteroids pehle destroy karke
mass increase karna greedy choice hai.

------------------------------------------------

TC:

Sorting -> O(n log n)

Traversal -> O(n)

Total:
O(n log n)

------------------------------------------------

SC:

Only few variables used.

SC = O(1)

(Note: sorting STL internally may use stack space)

------------------------------------------------

Pattern:

Greedy
Sorting
Simulation
*/