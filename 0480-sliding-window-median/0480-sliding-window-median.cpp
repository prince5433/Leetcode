
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        // left stores the smaller half of the current window.
        // right stores the larger half of the current window.
        //
        // Multiset keeps elements sorted automatically
        // and allows duplicate values.
        multiset<int> left, right;

        // Stores the median of every window of size k.
        vector<double> ans;

        // i = starting index of the window.
        // j = ending index of the window.
        int i = 0;
        int j = 0;

        // Expand the window by moving j forward.
        while (j < nums.size()) {

            // STEP 1: INSERT THE NEW ELEMENT

            // We maintain this size condition:
            // left.size() == right.size()
            // OR left.size() == right.size() + 1
            //
            // If left has equal or fewer elements than right,
            // insert into left so it can have one extra element.
            //
            // Otherwise, insert into right to maintain balance.
            if (left.size() <= right.size()) {
                left.insert(nums[j]);
            }
            else {
                right.insert(nums[j]);
            }


            // STEP 2: MAINTAIN SORTED ORDER

            // Every element in left must be <= every element in right.
            //
            // We only need to compare the boundary elements:
            // Maximum of left and minimum of right.
            //
            // If maximum of left is greater, their positions are incorrect.
            if (!right.empty() && *left.rbegin() > *right.begin()) {

                // Get iterators to the two boundary elements.
                auto it1 = prev(left.end());  // Maximum of left.
                auto it2 = right.begin();     // Minimum of right.

                // Store their values before removing them.
                int a = *it1;
                int b = *it2;

                // Remove exactly one occurrence using iterators.
                // This is safe even when duplicate values exist.
                left.erase(it1);
                right.erase(it2);

                // Exchange their positions to restore sorted order.
                left.insert(b);
                right.insert(a);
            }


            // STEP 3: CHECK WHETHER WINDOW SIZE IS k

            // Current window contains elements from index i to j.
            // Total window size = j - i + 1.
            if (j - i + 1 == k) {

                // STEP 4: CALCULATE THE MEDIAN

                // For odd k:
                // left contains one extra element.
                // Its maximum element is the middle element.
                if (k % 2 == 1) {
                    ans.push_back(*left.rbegin());
                }

                // For even k:
                // Both sets contain the same number of elements.
                // The two middle elements are:
                // Maximum of left and minimum of right.
                else {
                    ans.push_back(
                        ((double)*left.rbegin() + *right.begin()) / 2.0
                    );
                }


                // STEP 5: REMOVE THE OUTGOING ELEMENT

                // nums[i] is the element that will leave the window.
                int x = nums[i];

                // First search for x in left.
                auto it = left.find(x);

                if (it != left.end()) {

                    // If found, remove only that one occurrence.
                    left.erase(it);
                }
                else {

                    // Otherwise, x must be present in right.
                    // Find its iterator and remove one occurrence.
                    auto it = right.find(x);
                    right.erase(it);
                }

                // Move the starting pointer forward.
                // This slides the window by one position.
                i++;
            }


            // STEP 6: REBALANCE THE SETS

            // Insertion or deletion can disturb the size condition.
            // We restore the condition:
            // left.size() == right.size()
            // OR left.size() == right.size() + 1.

            // CASE 1:
            // right has more elements than left.
            // Move the smallest element of right into left.
            if (left.size() < right.size()) {

                // Get iterator to the smallest element of right.
                auto it = right.begin();

                // Insert its value into left.
                left.insert(*it);

                // Remove its old occurrence from right.
                right.erase(it);
            }

            // CASE 2:
            // left has more than one extra element.
            // Move its maximum element into right.
            else if (left.size() > right.size() + 1) {

                // Get iterator to the maximum element of left.
                auto it = prev(left.end());

                // Insert that value into right.
                right.insert(*it);

                // Remove its old occurrence from left.
                left.erase(it);
            }


            // STEP 7: MOVE THE END POINTER

            // Include the next element in the upcoming window.
            j++;
        }

        // Return the median of every window.
        return ans;
    }
};

// TC: O(n log k)
// SC: O(k)
