class Solution {
public:
    int fillCups(vector<int>& amount) {

        // total cups to fill (all 3 types combined)
        int sum = amount[0] + amount[1] + amount[2];

        // maximum cups among the three types
        int mx = max({amount[0], amount[1], amount[2]});

        // minimum time must be:
        // 1) at least mx seconds (largest type needs mx seconds, 1 cup/sec max for same type)
        // 2) at least ceil(sum/2) seconds (in 1 second, at most 2 cups can be filled)
        // answer is the maximum of these two lower bounds
        return max(mx, (sum + 1) / 2);
    }
};
