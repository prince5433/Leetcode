class Solution {
public:
    vector<vector<int>> dp;
    int n;
//bottom up
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        n = items.size();

        // val[i] = Current item kharidne par
        // total kitne items count honge.
        vector<int> val(n, 1);

        int mini = INT_MAX;

        // ================= Precomputation =================
        //
        // Har item ki value calculate karenge.
        // Agar kisi doosre item ka price current item ke
        // price ka multiple hai, toh uski value increase hogi.

        for (int i = 0; i < n; i++) {

            mini = min(mini, items[i][1]);

            for (int j = 0; j < n; j++) {

                // Same item ko dobara count nahi karna.
                if (i != j &&
                    items[j][0] % items[i][0] == 0) {

                    val[i]++;
                }
            }
        }

        // ================= DP Initialization =================
        //
        // dp[idx][rem_budget] =
        // Index idx se aage ke items consider karte hue,
        // rem_budget ke saath maximum items.
        //
        // n+1 rows chahiye kyunki idx == n bhi ek valid state hai.

        dp.assign(n + 1, vector<int>(budget + 1, 0));

        // ================= Base Case =================
        //
        // Top-Down:
        // if(idx == n)
        //     return rem_budget / mini;
        //
        // Saare items consider ho gaye.
        // Ab remaining budget se cheapest item jitni baar
        // kharid sakte hain, utne additional items milenge.
        //
        // Same base case ko DP table mein initialize karenge.

        for (int rem_budget = 0; rem_budget <= budget; rem_budget++) {

            dp[n][rem_budget] = rem_budget / mini;
        }

        // ================= Bottom-Up DP =================
        //
        // Top-Down recurrence:
        //
        // skip = solve(idx + 1, rem_budget)
        //
        // buy = val[idx] +
        //       solve(idx + 1, rem_budget - items[idx][1])
        //
        // dp[idx][rem_budget] = max(buy, skip)
        //
        // Dono choices next index par depend karti hain.
        // Isliye idx ko reverse order mein process karenge.

        for (int idx = n - 1; idx >= 0; idx--) {

            // Har possible remaining budget ke liye answer calculate karo.
            for (int rem_budget = 0; rem_budget <= budget; rem_budget++) {

                // ---------------- Option 1: Skip ----------------
                //
                // Current item nahi kharidna.
                // Budget same rahega aur next item consider hoga.
                int skip = dp[idx + 1][rem_budget];

                // ---------------- Option 2: Buy ----------------
                //
                // Initially 0, kyunki agar budget kam hai
                // toh current item kharidna possible nahi hoga.
                int buy = 0;

                if (rem_budget >= items[idx][1]) {

                    // Current item kharidne par uski value add hogi.
                    // Remaining budget ke saath next index ka answer
                    // pehle se calculate ho chuka hai.
                    buy = val[idx] +
                          dp[idx + 1][rem_budget - items[idx][1]];
                }

                // Same recursive recurrence:
                // Buy aur skip mein se maximum answer choose karo.
                dp[idx][rem_budget] = max(buy, skip);
            }
        }

        // Initially index 0 aur full budget available hai.
        return dp[0][budget];
    }
};

/*
==================== Top-Down -> Bottom-Up ====================

solve(idx, rem_budget)
    -> dp[idx][rem_budget]

solve(idx + 1, rem_budget)
    -> dp[idx + 1][rem_budget]

solve(idx + 1, rem_budget - items[idx][1])
    -> dp[idx + 1][rem_budget - items[idx][1]]

Same recursive recurrence:

skip = dp[idx + 1][rem_budget]

buy = val[idx] +
      dp[idx + 1][rem_budget - items[idx][1]]

dp[idx][rem_budget] = max(buy, skip)

Same base case:

dp[n][rem_budget] = rem_budget / mini

==================== Time Complexity ====================

Precomputation:
O(n^2)

Bottom-Up DP:
O(n × budget)

Overall TC = O(n^2 + n × budget)

==================== Space Complexity ====================

DP Array = O(n × budget)

val Array = O(n)

Overall SC = O(n × budget)
*/