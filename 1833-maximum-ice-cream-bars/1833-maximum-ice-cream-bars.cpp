class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        /*
        Intuition:

        Maximum number of ice creams chahiye.

        To hamesha cheapest ice cream
        pehle kharidni chahiye.

        This is a classic Greedy approach.
        */

        // Sort prices in increasing order
        sort(costs.begin(), costs.end());

        long long ans = 0;

        // Total money spent so far
        long long sum = 0;

        int n = costs.size();

        for (int i = 0; i < n; i++) {

            // Buy current cheapest ice cream
            sum += costs[i];

            /*
            If budget still allows,
            count this ice cream.
            */
            if (sum <= coins)
                ans++;
        }

        return ans;
    }
};

/*
---------------- QUICK INTUITION ----------------

Example:

costs = [1,3,2,4,1]

coins = 7

--------------------------------

After Sorting:

[1,1,2,3,4]

--------------------------------

Buy 1

sum = 1

count = 1

--------------------------------

Buy 1

sum = 2

count = 2

--------------------------------

Buy 2

sum = 4

count = 3

--------------------------------

Buy 3

sum = 7

count = 4

--------------------------------

Buy 4

sum = 11 > 7

Cannot afford.

Answer = 4

------------------------------------------------

Why Greedy Works?

Suppose you buy expensive
ice cream first.

Then fewer coins remain.

To maximize quantity,
always buy cheapest available.

Exactly same idea as:

"Maximum items under budget"

------------------------------------------------

Small Optimization

Current code continues loop
even after budget exceeds.

Can stop immediately:

if(sum > coins)
    break;

This avoids unnecessary iterations.

------------------------------------------------

Optimized Loop

for(int cost : costs){
    sum += cost;

    if(sum > coins)
        break;

    ans++;
}

------------------------------------------------

TC

Sorting:
O(n log n)

Traversal:
O(n)

Total:
O(n log n)

------------------------------------------------

SC

Sorting only.

Extra Space:

O(1)

(ignoring sort internals)

------------------------------------------------

Pattern

Greedy
Sorting
Maximum Items Under Budget
*/