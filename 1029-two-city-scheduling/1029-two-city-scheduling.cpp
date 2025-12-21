class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {

        // n = number of people to send to each city
        int n = costs.size() / 2;

        // Sort people based on the difference:
        // (cost to A - cost to B)
        // Smaller difference → City A is cheaper
        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });

        int tc = 0; // total cost

        // First n people → City A
        for(int i = 0; i < n; i++){
            tc += costs[i][0];
        }

        // Remaining n people → City B
        for(int i = n; i < 2 * n; i++){
            tc += costs[i][1];
        }

        return tc;
    }
};
