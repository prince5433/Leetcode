
class Solution {
public:
    typedef long long ll;

    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        // =====================================================
        // STEP 1: PREFIX SUM
        // =====================================================

        // cumSum[i] stores sum of nums[0] to nums[i-1].
        //
        // Size n+1 isliye liya hai taaki range sum easily
        // calculate kar sakein without handling index -1.
        //
        // Example:
        // nums   = [3, 1, 4, 2]
        // cumSum = [0, 3, 4, 8, 10]

        vector<ll> cumSum(n + 1, 0);

        for(int i = 0; i < n; i++) {

            // Previous prefix sum + current element.
            cumSum[i + 1] = cumSum[i] + nums[i];
        }

        // Range sum from index i to j.
        //
        // Formula:
        // sum(i,j) = cumSum[j+1] - cumSum[i]
        //
        // Example:
        // nums = [3,1,4,2]
        // sum(1,3) = 1+4+2 = 7
        //
        // Each range sum takes O(1) time.

        auto rangeSum = [&](int i, int j) -> ll {

            // Empty range means sum is zero.
            if(i > j) return 0LL;

            return cumSum[j + 1] - cumSum[i];
        };


        // =====================================================
        // STEP 2: NEXT GREATER ELEMENT (NGE)
        // =====================================================

        // nge[i] stores the INDEX of the first element
        // on the right side which is STRICTLY GREATER than nums[i].
        //
        // If no greater element exists, nge[i] = n.
        //
        // Example:
        // nums = [3, 1, 4, 2]
        // nge  = [2, 2, 4, 4]
        //
        // Index 2 par value 4 is greater than nums[0] = 3.
        // Index 2 par value 4 is also greater than nums[1] = 1.
        // For index 2 and 3, no greater element exists.

        vector<int> nge(n);

        // Monotonic stack stores indices, NOT values.
        stack<int> st;

        // Right se left traversal because humein
        // har element ka next greater element RIGHT mein chahiye.
        for(int i = n - 1; i >= 0; i--) {

            // Remove all elements which are smaller than
            // OR equal to nums[i].
            //
            // Why <= ?
            // Because we need a STRICTLY GREATER element.
            //
            // Also, these removed elements cannot be the
            // next greater element for current index.

            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            // If stack is empty, no greater element exists.
            // Otherwise, stack top is the nearest greater index.

            if(st.empty()) {
                nge[i] = n;
            }
            else {
                nge[i] = st.top();
            }

            // Push current index for future elements.
            st.push(i);
        }

        // Every index is pushed once and popped at most once.
        // Total NGE complexity = O(n).


        // =====================================================
        // STEP 3: OPERATIONS ARRAY
        // =====================================================

        // operations[i] represents the minimum number of
        // increment operations needed to make the entire
        // suffix nums[i...n-1] non-decreasing.
        //
        // We calculate it from RIGHT TO LEFT.
        //
        // operations[n] = 0 because there are no elements
        // after the last index.

        vector<ll> operations(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {

            // m = next greater element's index.
            int m = nge[i];

            // Between i and m-1, all elements are <= nums[i].
            //
            // To make this segment non-decreasing,
            // we need to increase every element in this segment
            // to at least nums[i].
            //
            // Number of elements = m-i.
            //
            // Required final sum = nums[i] * (m-i).
            //
            // Existing sum = rangeSum(i,m-1).
            //
            // Required increments = final sum - existing sum.

            ll segmentOps =
                1LL * nums[i] * (m - i)
                - rangeSum(i, m - 1);

            // After index m, we continue using the already
            // calculated operations[m].
            //
            // Therefore:
            // operations[i] =
            // current segment operations + remaining suffix operations.

            operations[i] = segmentOps + operations[m];
        }


        // =====================================================
        // STEP 4: SLIDING WINDOW + MONOTONIC DEQUE
        // =====================================================

        // Deque stores indices in decreasing order of values.
        //
        // Front = index of maximum element in current window.
        //
        // Back = smallest element among the indices currently stored.

        deque<int> dq;

        // Total number of valid subarrays.
        // long long is necessary because answer can be large.
        ll result = 0;

        // Sliding window boundaries:
        // Current window = [i...j]
        int i = 0;
        int j = 0;

        // Expand window from left to right.
        while(j < n) {

            // Maintain decreasing order in deque.
            //
            // If nums[dq.back()] <= nums[j], remove it.
            //
            // Why?
            // Current element is greater than or equal to that element.
            // So the previous element cannot be the maximum
            // as long as current element is inside the window.

            while(!dq.empty() && nums[dq.back()] <= nums[j]) {
                dq.pop_back();
            }

            // Insert current index.
            dq.push_back(j);


            // =================================================
            // STEP 5: CHECK WHETHER CURRENT WINDOW IS VALID
            // =================================================

            // We need minimum increments to make nums[i...j]
            // non-decreasing.
            //
            // If required operations > k, shrink window
            // from the left side.

            while(i <= j) {

                // m = index of maximum element in current window.
                //
                // IMPORTANT:
                // Recalculate inside the while loop because
                // removing the leftmost index can change dq.front().

                int m = dq.front();

                // Calculate minimum operations required
                // to make the current window non-decreasing.
                //
                // PART 1:
                // operations[i] - operations[m]
                //
                // This gives the operations needed for
                // the portion from i to m-1.
                //
                // PART 2:
                // nums[m] * (j-m+1) - rangeSum(m,j)
                //
                // From m to j, we need to make every element
                // at least nums[m].
                //
                // Number of elements = j-m+1.
                // Required final sum = nums[m] * (j-m+1).
                // Existing sum = rangeSum(m,j).
                //
                // Total = PART 1 + PART 2.

                ll operationsCount =
                    (operations[i] - operations[m])
                    +
                    (1LL * nums[m] * (j - m + 1))
                    -
                    rangeSum(m, j);


                // If operations needed are within budget,
                // current window is valid.
                if(operationsCount <= k) {
                    break;
                }

                // Current window is invalid.
                // Remove the leftmost element by moving i forward.
                i++;

                // Remove indices which are no longer inside
                // the current window.
                //
                // If deque front index < i, it is outside the window.
                if(!dq.empty() && dq.front() < i) {
                    dq.pop_front();
                }
            }


            // =================================================
            // STEP 6: COUNT VALID SUBARRAYS
            // =================================================

            // Current window [i...j] is valid.
            //
            // Because increasing the left boundary can only
            // reduce the operations required, all these
            // subarrays are also valid:
            //
            // [i...j]
            // [i+1...j]
            // [i+2...j]
            // ...
            // [j...j]
            //
            // Total valid subarrays ending at j = j-i+1.

            result += (j - i + 1);

            // Expand window by moving right pointer.
            j++;
        }

        return result;
    }
};


/*
=========================================================
TIME COMPLEXITY
=========================================================

Let n = nums.size().

1. PREFIX SUM:
   One loop runs n times.
   Each iteration performs O(1) work.
   TC = O(n).

2. NGE:
   Each index is pushed into stack exactly once.
   Each index can be popped at most once.
   Total stack operations = O(n).
   TC = O(n).

3. OPERATIONS ARRAY:
   One loop runs n times.
   Each iteration uses O(1) rangeSum.
   TC = O(n).

4. SLIDING WINDOW + DEQUE:
   Right pointer j moves at most n times.
   Left pointer i moves at most n times.
   Each index enters deque once.
   Each index leaves deque at most once.
   Total deque operations = O(n).
   TC = O(n).

FINAL TIME COMPLEXITY:

O(n) + O(n) + O(n) + O(n)

= O(4n)

= O(n).


=========================================================
SPACE COMPLEXITY
=========================================================

1. cumSum array   = O(n)
2. nge array      = O(n)
3. Stack          = O(n)
4. operations     = O(n)
5. Deque          = O(n)

FINAL SPACE COMPLEXITY:

O(n) + O(n) + O(n) + O(n) + O(n)

= O(5n)

= O(n).
=========================================================
*/
