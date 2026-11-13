
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        // Deque stores INDEXES, not actual values.
        //
        // We maintain decreasing order of values
        // corresponding to these indexes.
        //
        // Front of deque = index of maximum element
        // in the current sliding window.

        deque<int> dq;

        // Stores maximum element of every window.
        vector<int> result;


        // Traverse the array from left to right.
        for(int i = 0; i < n; i++) {


            // STEP 1: REMOVE OUT-OF-WINDOW INDEXES
            //
            // Current window starts at index i-k+1.
            //
            // Any index <= i-k is outside the current window.
            //
            // Example:
            // i = 3, k = 3
            // Current window = [1,2,3]
            // Index 0 is outside the window.
            //
            // Deque front is the oldest candidate,
            // so remove it if it is outside.

            while(!dq.empty() && dq.front() <= i-k) {

                dq.pop_front();
                // O(1)
            }


            // STEP 2: MAINTAIN DECREASING ORDER
            //
            // Remove all elements from the back whose values
            // are smaller than the current element.
            //
            // Why?
            // Current element is greater and comes later.
            // Therefore, smaller previous elements can never
            // become the maximum while current element is in window.
            //
            // IMPORTANT:
            // dq.back() stores an index.
            // nums[dq.back()] gives its actual value.

            while(!dq.empty() && nums[i] > nums[dq.back()]) {

                dq.pop_back();
                // O(1)
            }


            // STEP 3: INSERT CURRENT INDEX
            //
            // Current index becomes a candidate for maximum.
            dq.push_back(i);
            // O(1)


            // STEP 4: STORE ANSWER
            //
            // A complete window is formed when i >= k-1.
            //
            // Example:
            // k = 3
            // First complete window is at index 2.
            //
            // Since deque is maintained in decreasing order,
            // its front contains the maximum element's index.

            if(i >= k-1) {

                result.push_back(nums[dq.front()]);
                // O(1)
            }
        }

        return result;
    }
};

/*
TIME COMPLEXITY:

1. Outer loop:
   Runs n times = O(n).

2. First while loop:
   Removes indexes outside the window.
   Every index enters deque once and leaves at most once.

3. Second while loop:
   Removes smaller elements from the back.
   Every index enters deque once and leaves at most once.

4. push_back and pop operations:
   Each takes O(1).

Although there are two while loops inside the for loop,
their total number of iterations across the entire algorithm
is O(n), not O(n*k).

FINAL TC = O(n).


SPACE COMPLEXITY:

Deque stores at most k indexes = O(k).
Result stores n-k+1 elements = O(n-k+1).

Auxiliary SC excluding output = O(k).
Including result vector = O(n).

FINAL SC = O(n).
*/
