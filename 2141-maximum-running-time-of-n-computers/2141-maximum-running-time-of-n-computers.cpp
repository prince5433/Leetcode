class Solution {
public:
#define ll long long

    // Check if we can run all n computers for t minutes
    bool can(long long t, int n, vector<int>& batteries) {
        long long total = 0;

        // Each battery can contribute at most min(battery, t)
        for (long long b : batteries) {
            total += min(b, t);

            // If total available power becomes enough to run n computers for t minutes
            // i.e., total >= t * n → valid
            if (total >= t * n) return true;
        }
        return false; // not enough total energy
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        ll lo = 0;
        ll hi = accumulate(batteries.begin(), batteries.end(), 0LL); // maximum possible time (upper bound)
        ll ans = 0;

        // Binary search on maximum possible running time
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;  // t = candidate running time

            // If t = mid minutes is possible, try for longer time
            if (can(mid, n, batteries)) {
                ans = mid;
                lo = mid + 1;
            } 
            // Otherwise try for smaller time
            else {
                hi = mid - 1;
            }
        }
        return ans; // highest valid time
    }
};
