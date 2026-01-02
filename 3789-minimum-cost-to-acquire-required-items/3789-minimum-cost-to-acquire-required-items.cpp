class Solution {
public:
    #define ll long long   // long long ke liye short form

    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        // Pehle common units cover karte hain
        // min(need1, need2) times:
        // ya to alag-alag lo (cost1 + cost2)
        // ya dono ek saath lo (costBoth)
        ll mincost = min(need1, need2) * 
                     (ll)min(cost1 + cost2, costBoth);

        // Agar need1 zyada hai to extra need1 ko cover karo
        // ya to sirf cost1 se
        // ya costBoth se (agar sasta ho)
        if (need1 > need2) {
            mincost += (ll)min(cost1, costBoth) * (need1 - need2);
        }
        // Agar need2 zyada hai to extra need2 ko cover karo
        else {
            mincost += (ll)min(cost2, costBoth) * (need2 - need1);
        }

        return mincost;  // total minimum cost
    }
};
