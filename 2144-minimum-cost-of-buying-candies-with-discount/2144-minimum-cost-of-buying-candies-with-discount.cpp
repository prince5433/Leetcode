class Solution {
public:
    int minimumCost(vector<int>& cost) {

        /*
        Intuition:

        Offer:
        Buy 2 candies,
        get 1 candy free.

        To maximize discount,
        expensive candies ko group me rakho.

        So sort in descending order.

        Example:
        [6,5,4]

        Pay:
        6 + 5

        Free:
        4
        */

        // Expensive candies first
        sort(cost.rbegin(), cost.rend());

        int sum = 0;

        for(int i = 0; i < cost.size(); i++) {

            /*
            Every 3rd candy becomes free.

            Indices:
            0 1 2
            P P F

            3 4 5
            P P F
            */
            if((i + 1) % 3 == 0)
                continue;

            // Add cost of paid candy
            sum += cost[i];
        }

        return sum;
    }
};

/*
---------------- QUICK INTUITION ----------------

Example:

cost = [6,5,4,3,2,1]

After sorting:
[6,5,4,3,2,1]

Groups:

(6,5,4)
Pay = 6 + 5
Free = 4

(3,2,1)
Pay = 3 + 2
Free = 1

Answer:
6 + 5 + 3 + 2 = 16

------------------------------------------------

Why Greedy?

To get maximum discount,
free candy should be as expensive as possible.

Sorting descending automatically makes
every 3rd candy the best possible free candy.

------------------------------------------------

TC:

Sorting:
O(n log n)

Traversal:
O(n)

Total:
O(n log n)

------------------------------------------------

SC:

O(1)

(ignoring sorting space)

------------------------------------------------

Pattern:

Greedy
Sorting
Simulation
*/