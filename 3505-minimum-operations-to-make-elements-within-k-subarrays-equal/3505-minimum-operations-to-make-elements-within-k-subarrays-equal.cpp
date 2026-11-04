
class Solution {
public:

    // STEP 2: TOP-DOWN PICK / NOT PICK DP
    //
    // i = current index in the precomputed cost vector.
    // k = number of subarrays still required.
    //
    // solve(i, k) returns minimum cost to select exactly
    // k non-overlapping subarrays from cost[i ... end].
    long long solve(int i, int k, int x,
                    vector<long long>& cost,
                    vector<vector<long long>>& dp) {

        // Base case:
        // We have selected all required subarrays.
        // No more operations are required.
        if (k == 0) return 0;

        // If no subarray is left, we cannot select more.
        if (i >= cost.size()) return 1e18;

        // If remaining windows are fewer than required selections,
        // it is impossible to complete the selection.
        if (cost.size() - i < k) return 1e18;

        // If this state was already calculated, reuse its answer.
        // This avoids solving the same subproblem repeatedly.
        if (dp[i][k] != -1) return dp[i][k];


        // CHOICE 1: NOT PICK

        // Skip the current subarray.
        // Move to the next possible starting index.
        long long notPick = solve(i + 1, k, x, cost, dp);


        // CHOICE 2: PICK

        // Select the current subarray.
        // Its equalization cost is cost[i].
        //
        // Since its size is x, the next subarray can only start
        // from index i+x to avoid overlapping.
        long long pick = cost[i] +
                         solve(i + x, k - 1, x, cost, dp);


        // Store and return the minimum cost among both choices.
        return dp[i][k] = min(pick, notPick);
    }


    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        // Same two multisets as LeetCode 480:
        // left stores smaller half of the current window.
        // right stores larger half of the current window.
        multiset<int> left, right;

        // Stores minimum operations required for every
        // possible subarray of size x.
        vector<long long> cost;

        // Maintain sums of both multisets.
        // These help calculate the equalization cost in O(1).
        long long sumLeft = 0, sumRight = 0;

        // i = starting index of the sliding window.
        // j = ending index of the sliding window.
        int i = 0, j = 0;


        // STEP 1: SLIDING WINDOW + COST PRECOMPUTATION

        while (j < n) {

            // STEP 1.1: INSERT THE NEW ELEMENT

            // Maintain the size condition:
            // left.size() == right.size()
            // OR left.size() == right.size() + 1.
            //
            // If left is empty or has equal/fewer elements,
            // insert the new value into left.
            if (left.size() == 0 || left.size() <= right.size()) {

                left.insert(nums[j]);

                // Update sum because this element belongs to left.
                sumLeft += nums[j];
            }
            else {

                // Otherwise insert into right.
                right.insert(nums[j]);

                // Update sum of right.
                sumRight += nums[j];
            }


            // STEP 1.2: MAINTAIN SORTED ORDER

            // Every element of left must be <= every element of right.
            //
            // Compare only the boundary elements:
            // Maximum of left and minimum of right.
            //
            // If the maximum of left is greater, exchange them.
            if (!right.empty() && *left.rbegin() > *right.begin()) {

                // Iterator to maximum element of left.
                auto it1 = prev(left.end());

                // Iterator to minimum element of right.
                auto it2 = right.begin();

                // Store values before removing the elements.
                int a = *it1;
                int b = *it2;

                // Remove one occurrence from both sets.
                left.erase(it1);
                right.erase(it2);

                // Put the smaller value in left
                // and the larger value in right.
                left.insert(b);
                right.insert(a);

                // Update sums according to the exchanged values.
                sumLeft += (long long)b - a;
                sumRight += (long long)a - b;
            }


            // STEP 1.3: CHECK WHETHER WINDOW SIZE IS x

            // Current window contains indices i to j.
            // Its size is j-i+1.
            if (j - i + 1 == x) {

                // STEP 1.4: FIND MEDIAN

                // left always has equal or one extra element.
                // Therefore, its maximum is the median.
                long long median = *left.rbegin();


                // STEP 1.5: CALCULATE MINIMUM OPERATIONS

                // Every element in left is <= median.
                //
                // To make all left elements equal to median:
                // operations = median * number of elements - sumLeft.
                long long leftCost =
                    median * left.size() - sumLeft;

                // Every element in right is >= median.
                //
                // To make all right elements equal to median:
                // operations = sumRight - median * number of elements.
                long long rightCost =
                    sumRight - median * right.size();

                // Total minimum operations for this window.
                long long operations = leftCost + rightCost;


                // STEP 1.6: STORE THE PRECOMPUTED COST

                // cost[0] represents the first window.
                // cost[1] represents the second window, and so on.
                //
                // We store only costs because DP needs no
                // information about the original elements.
                cost.push_back(operations);


                // STEP 1.7: REMOVE OUTGOING ELEMENT

                // nums[i] is leaving the current window.
                int val = nums[i];

                // First check whether this value exists in left.
                auto it = left.find(val);

                if (it != left.end()) {

                    // Remove exactly one occurrence from left.
                    left.erase(it);

                    // Update left's sum after deletion.
                    sumLeft -= val;
                }
                else {

                    // Otherwise, the outgoing element belongs to right.
                    auto it2 = right.find(val);

                    // Remove exactly one occurrence from right.
                    right.erase(it2);

                    // Update right's sum.
                    sumRight -= val;
                }

                // Move the starting pointer forward.
                // This prepares the next sliding window.
                i++;
            }


            // STEP 1.8: REBALANCE AFTER INSERTION / DELETION

            // After removing the outgoing element, set sizes
            // might become unequal in an invalid way.

            // CASE 1:
            // If right has more elements than left,
            // move the smallest element of right into left.
            if (left.size() < right.size()) {

                // Get iterator to the smallest element of right.
                auto it = right.begin();

                int val = *it;

                // Insert into left and update its sum.
                left.insert(val);
                sumLeft += val;

                // Remove the old occurrence from right.
                right.erase(it);
                sumRight -= val;
            }

            // CASE 2:
            // If left has more than one extra element,
            // move its maximum element into right.
            else if (left.size() > right.size() + 1) {

                // Get iterator to maximum element of left.
                auto it = prev(left.end());

                int val = *it;

                // Insert into right and update its sum.
                right.insert(val);
                sumRight += val;

                // Remove the old occurrence from left.
                left.erase(it);
                sumLeft -= val;
            }


            // Move j forward to include the next element.
            j++;
        }


        // STEP 2: APPLY TOP-DOWN DP ON THE COST VECTOR

        // Number of possible size-x subarrays.
        int m = cost.size();

        // dp[i][k] stores minimum cost to select exactly k
        // non-overlapping subarrays from cost[i ... m-1].
        //
        // -1 means this state has not been calculated yet.
        vector<vector<long long>> dp(
            m + 1, vector<long long>(k + 1, -1)
        );


        // Start from the first possible subarray.
        // We need to select exactly k subarrays.
        return solve(0, k, x, cost, dp);
    }
};

// TC: O(n log x + n*k)
// SC: O(x + n*k)
