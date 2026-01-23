class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());      // descending sort (expensive candies first)

        int sum = 0;

        for(int i = 0; i < cost.size(); i++){
            if((i + 1) % 3 == 0) continue;     // every 3rd candy free (in each group of 3)
            sum += cost[i];                    // add only paid candies
        }

        return sum;                            // total minimum cost
    }
};
