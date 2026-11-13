
class Solution {
public:
    typedef long long ll;

    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        // Prefix Sum
        vector<ll> cumSum(n + 1, 0);

        for(int i = 0; i < n; i++) {
            cumSum[i + 1] = cumSum[i] + nums[i];
        }

        auto rangeSum = [&](int i, int j) -> ll {
            if(i > j) return 0LL;
            return cumSum[j + 1] - cumSum[i];
        };

        // Next Greater Element: store indices, not values.
        vector<int> nge(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            nge[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        // Operations required for suffix starting at i.
        vector<ll> operations(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {

            int m = nge[i];

            ll segmentOps = 1LL * nums[i] * (m - i)
                          - rangeSum(i, m - 1);

            operations[i] = segmentOps + operations[m];
        }

        // Sliding Window + Monotonic Deque
        deque<int> dq;

        ll result = 0;

        int i = 0;
        int j = 0;

        while(j < n) {

            // Maintain decreasing order of values.
            while(!dq.empty() && nums[dq.back()] <= nums[j]) {
                dq.pop_back();
            }

            dq.push_back(j);

            // Shrink window until operations <= k.
            while(i <= j) {

                // IMPORTANT: Recalculate maximum index
                // whenever the left boundary changes.
                int m = dq.front();

                ll operationsCount =
                    (operations[i] - operations[m])
                    + (1LL * nums[m] * (j - m + 1))
                    - rangeSum(m, j);

                if(operationsCount <= k) {
                    break;
                }

                i++;

                // Remove indices outside current window.
                if(!dq.empty() && dq.front() < i) {
                    dq.pop_front();
                }
            }

            // All subarrays ending at j and starting from i to j
            // are valid.
            result += (j - i + 1);

            j++;
        }

        return result;
    }
};

/*
TIME COMPLEXITY:

Prefix Sum: O(n)
NGE: O(n), each index pushed/popped at most once.
Operations: O(n)
Sliding Window + Deque: O(n), each index enters/leaves deque once.

Total TC = O(n).

SPACE COMPLEXITY:

Prefix Sum = O(n)
NGE = O(n)
Stack = O(n)
Operations = O(n)
Deque = O(n)

Total SC = O(n).
*/
