class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        /*
        Intuition:

        Final array me order chahiye:

        [elements < pivot]
        [elements = pivot]
        [elements > pivot]

        Relative order bhi maintain karna hai.

        So 3 separate arrays bana lo.
        */

        vector<int> less, greater, equal;

        // Divide elements into 3 groups
        for (int num : nums) {

            if (num < pivot)
                less.push_back(num);

            else if (num > pivot)
                greater.push_back(num);

            else
                equal.push_back(num);
        }

        /*
        Concatenate:

        less + equal + greater
        */

        less.insert(less.end(), equal.begin(), equal.end());

        less.insert(less.end(), greater.begin(), greater.end());

        return less;
    }
};

/*
---------------- QUICK INTUITION ----------------

Example:

nums = [9,12,5,10,14,3,10]
pivot = 10

less:
[9,5,3]

equal:
[10,10]

greater:
[12,14]

Answer:
[9,5,3,10,10,12,14]

------------------------------------------------

Why this works?

Har element exactly ek group me jayega.

Fir groups ko required order me
merge kar diya.

Relative order automatically preserved
because push_back order same hai.

------------------------------------------------

TC:

Traversal -> O(n)

Insert all elements once -> O(n)

Total:
O(n)

------------------------------------------------

SC:

3 extra vectors

O(n)

------------------------------------------------

Pattern:

Three-Way Partitioning
Array Partition
Simulation
*/