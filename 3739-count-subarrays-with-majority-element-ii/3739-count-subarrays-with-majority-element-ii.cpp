class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        /*
        Intuition:

        Convert the array into:

        target     -> +1
        non-target -> -1

        Now we need to count
        subarrays whose transformed
        sum is positive (> 0).

        A positive sum means:

        target appears more than
        all other elements combined,

        i.e. target is the majority.
        */

        unordered_map<int,int> mp;

        // Prefix sum = 0 occurs once
        mp[0] = 1;

        // Current prefix sum
        int cumsum = 0;

        /*
        validleftpoints stores
        how many previous prefix sums
        can form a positive-sum
        subarray ending at current index.
        */
        long long validleftpoints = 0;

        long long result = 0;

        for(int j = 0; j < nums.size(); j++) {

            /*
            Target contributes +1.
            */
            if(nums[j] == target) {

                /*
                Every previous prefix
                having same cumsum
                now becomes valid.
                */
                validleftpoints += mp[cumsum];

                cumsum += 1;
            }
            else {

                /*
                Non-target contributes -1.
                */
                cumsum -= 1;

                /*
                Prefixes having this
                updated cumsum
                are no longer valid.
                */
                validleftpoints -= mp[cumsum];
            }

            // Store current prefix sum
            mp[cumsum]++;

            // Add all valid subarrays
            // ending at current index
            result += validleftpoints;
        }

        return result;
    }
};

/*
---------------- QUICK INTUITION ----------------

Majority means:

target count >

remaining elements

------------------------------------------------

Transformation

target

→ +1

Others

→ -1

------------------------------------------------

Example

nums:

[2,1,2]

target = 2

Transform

[+1,-1,+1]

------------------------------------------------

Prefix Sum

0

1

0

1

------------------------------------------------

Positive subarray sum

means

more +1

than

-1

Therefore

target is majority.

------------------------------------------------

Why validleftpoints?

Suppose

Current index = j

Need number of
starting positions
such that

subarray sum > 0

Instead of checking
every left index,

we maintain

validleftpoints

incrementally.

------------------------------------------------

Dry Run

nums

[2]

target

2

--------------------------------

mp

{0:1}

cumsum

0

--------------------------------

2

Target

valid += mp[0]

= 1

cumsum = 1

mp[1]++

result += 1

Answer = 1

------------------------------------------------

Example

nums

[2,1]

Transform

+1 -1

--------------------------------

After first element

valid = 1

result = 1

--------------------------------

Second element

cumsum decreases

Some prefixes
become invalid

valid decreases

Result remains correct.

------------------------------------------------

TC

Single traversal

O(n)

------------------------------------------------

SC

HashMap

stores prefix sums

O(n)

------------------------------------------------

Pattern

Prefix Sum

HashMap

Running Count

Majority Transformation

(+1 / -1)
*/