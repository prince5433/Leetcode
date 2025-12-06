class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        vector<int> diff;
        diff.reserve(n);           // reserve space to avoid reallocations
        long long total = 0;

        int idx = 0;

        // First choose technique2 for all players
        while (idx < n) {
            total += technique2[idx];                     // add default points of technique2
            diff.push_back(technique1[idx] - technique2[idx]);  // gain if we switch to technique1
            idx++;
        }

        // Sort gains in descending order
        sort(diff.begin(), diff.end());
        reverse(diff.begin(), diff.end());

        int t = 0;

        // Choose top k maximum gains (forced choice of technique1 exactly k times)
        while (t < k) {
            total += diff[t];      // add gain from switching to technique1
            t++;
        }

        // After k choices, we can still switch to technique1 for remaining people
        // ONLY if it increases total points (i.e., positive gain)
        while (t < n) {
            if (diff[t] > 0)
                total += diff[t];
            t++;
        }

        return total;
    }
};
