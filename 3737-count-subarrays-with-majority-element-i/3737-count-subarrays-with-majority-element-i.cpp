class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        // Stores count of valid subarrays
        int sub = 0;

        // Fix starting index
        for(int i = 0; i < n; i++) {

            // Count of target in current subarray
            int tc = 0;

            // Current subarray length
            int sl = 0;

            // Extend subarray till j
            for(int j = i; j < n; j++) {

                sl++;

                // Increase target count
                if(nums[j] == target)
                    tc++;

                /*
                Majority condition:

                target frequency >
                half of subarray length
                */
                if(tc > sl / 2)
                    sub++;
            }
        }

        return sub;
    }
};

/*
---------------- QUICK INTUITION ----------------

Need to count subarrays
where target is the majority.

Majority means:

frequency(target)
>
length(subarray) / 2

------------------------------------------------

Example

nums = [1,1,2]

target = 1

------------------------------------------------

Subarrays

[1]

tc = 1
len = 1

1 > 0

Valid ✅

--------------------------------

[1,1]

tc = 2
len = 2

2 > 1

Valid ✅

--------------------------------

[1,1,2]

tc = 2
len = 3

2 > 1

Valid ✅

--------------------------------

[1]

tc = 1
len = 1

Valid ✅

--------------------------------

[1,2]

tc = 1
len = 2

1 > 1 ?

No ❌

--------------------------------

[2]

tc = 0
len = 1

Invalid ❌

------------------------------------------------

Answer = 4

------------------------------------------------

Variables

tc

= count of target
in current subarray

--------------------------------

sl

= current subarray length

------------------------------------------------

Condition

tc > sl/2

Example:

Length = 5

Need:

tc > 2

So tc must be 3,4,5

------------------------------------------------

Dry Run

nums = [2,2]

target = 2

--------------------------------

i = 0

j = 0

tc = 1
sl = 1

1 > 0

count = 1

--------------------------------

j = 1

tc = 2
sl = 2

2 > 1

count = 2

--------------------------------

i = 1

j = 1

tc = 1
sl = 1

count = 3

------------------------------------------------

TC

Outer Loop:
O(n)

Inner Loop:
O(n)

Total:

O(n²)

------------------------------------------------

SC

Only variables used.

O(1)

------------------------------------------------

Pattern

Brute Force
Subarray Enumeration
Frequency Counting
Majority Element
*/