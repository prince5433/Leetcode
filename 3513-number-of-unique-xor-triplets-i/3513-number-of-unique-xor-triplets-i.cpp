class Solution {
public:

    int uniqueXorTriplets(vector<int>& nums) {

        // Total elements in permutation.
        int n = nums.size();

        // WHY n == 1 or n == 2?
        //
        // Itne chhote array me
        // jitne numbers hain,
        // utni hi unique XOR values possible hain.
        //
        // Example:
        //
        // n = 1
        //
        // [1]
        //
        // Answer = 1
        //
        // n = 2
        //
        // [1,2]
        //
        // Answer = 2
        if (n == 1 || n == 2)
            return n;

        // ans store karega
        // smallest power of 2
        // jo n se strictly badi ho.
        int ans = 1;

        // WHY smallest power of 2?
        //
        // XOR values binary representation
        // follow karti hain.
        //
        // Is problem ka observation hai ki
        // jab n >= 3 hota hai,
        // to saari XOR values
        // 0 se lekar
        // (Next Power of 2 - 1)
        // tak generate ho jaati hain.
        //
        // Isliye answer hamesha
        // next power of 2 hota hai.
        while (ans <= n) {

            ans *= 2;
        }

        return ans;
    }
};

/*
---------------- INTUITION ----------------

Array ek permutation hai

[1...n]

Aur hume

nums[i] XOR nums[j] XOR nums[k]

ke saare unique values count karne hain.

---------------- IMPORTANT OBSERVATION ----------------

Agar

n = 1

Answer = 1

----------------

n = 2

Answer = 2

----------------

Lekin

n >= 3

hone ke baad

XOR ki help se

0 se lekar

Next Power of 2 - 1

tak ki saari values
generate ho jaati hain.

Isliye

Answer

=

Next Power of 2

(strictly greater than n)

---------------- Example ----------------

n = 5

Next Power of 2

=

8

Answer

=

8

----------------

n = 9

Next Power of 2

=

16

Answer

=

16

---------------- WHY While Loop ----------------

ans initially

1

hai.

Har iteration me

2 se multiply karte hain.

Jab tak

ans > n

na ho jaaye.

Uske baad

ans hi smallest power of 2
greater than n hoti hai.

---------------- Time Complexity ----------------

Har iteration me

ans double hota hai.

Iterations

≈ log₂(n)

TC = O(log n)

---------------- Space Complexity ----------------

Koi extra data structure use nahi hua.

SC = O(1)

---------------- MATHEMATICAL OBSERVATION ----------------

For

n ≥ 3

Unique XOR Values

=

2^k

where

2^(k-1) ≤ n < 2^k

Matlab

Answer = Next Power of 2
greater than n.
*/