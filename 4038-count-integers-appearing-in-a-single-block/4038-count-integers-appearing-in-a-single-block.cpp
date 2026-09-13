class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        int n = nums.size();

        // freq[x]  -> x kitni baar array me present hai.
        // first[x] -> x ka first occurrence index.
        // last[x]  -> x ka last occurrence index.
        //
        // WHY ye 3 cheezein?
        //
        // Hume check karna hai ki x ki saari occurrences
        // first[x] se last[x] ke beech continuously hain ya nahi.
        unordered_map<int, int> freq, last, first;


        // ---------------- STEP 1 ----------------
        //
        // Har number ki:
        //
        // 1. Frequency
        // 2. First occurrence
        // 3. Last occurrence
        //
        // store karo.
        for (int i = 0; i < n; i++) {

            // Current number ki frequency increase karo.
            freq[nums[i]]++;


            // WHY first occurrence sirf ek baar store karni hai?
            //
            // Agar x pehli baar mila hai,
            // tabhi i uska first index hoga.
            //
            // Baad me aane wale occurrences ke liye
            // first index change nahi karna.
            if (first.find(nums[i]) == first.end()) {
                first[nums[i]] = i;
            }


            // WHY last occurrence har baar update?
            //
            // Har baar x milega,
            // current i uska latest occurrence hoga.
            //
            // Isliye loop ke end tak
            // last[x] automatically last occurrence ban jayega.
            last[nums[i]] = i;
        }


        int cnt = 0;


        // ---------------- STEP 2 ----------------
        //
        // Har unique number ko check karo
        // ki uski occurrences continuous hain ya nahi.
        for (auto it : freq) {

            int x = it.first;

            // first[x] -> first occurrence
            // last[x]  -> last occurrence
            //
            // Inke beech total positions:
            //
            // last[x] - first[x] + 1
            //
            // WHY +1?
            //
            // Example:
            //
            // first = 2
            // last = 4
            //
            // Positions:
            //
            // 2, 3, 4
            //
            // Total = 3
            //
            // Formula:
            //
            // 4 - 2 + 1 = 3


            // Agar range ke andar jitni positions hain
            // exactly utni hi baar x present hai,
            // to beech me koi other number nahi ho sakta.
            //
            // Matlab x ki saari occurrences continuous hain.
            if (last[x] - first[x] + 1 == freq[x]) {
                cnt++;
            }
        }


        return cnt;
    }
};

/*
---------------- INTUITION ----------------

Hume count karna hai ki
kitne numbers ki occurrences
array me continuous hain.

Example:

nums = [1, 2, 2, 3, 1]

For 2:

first[2] = 1
last[2]  = 2
freq[2]  = 2

Range length:

2 - 1 + 1 = 2

Frequency:

2

Dono equal hain.

=> 2 SPECIAL hai.


For 1:

first[1] = 0
last[1]  = 4
freq[1]  = 2

Range length:

4 - 0 + 1 = 5

Frequency:

2

Equal nahi hai.

=> 1 SPECIAL nahi hai.

---------------- WHY FORMULA WORKS ----------------

Suppose:

x ki first occurrence = 3
x ki last occurrence = 6

To range hai:

3, 4, 5, 6

Total positions:

6 - 3 + 1 = 4

Agar x ki frequency bhi 4 hai,

to:

4 positions
=
4 occurrences of x

Matlab range ke andar
koi bhi different element nahi ho sakta.

So:

last[x] - first[x] + 1 == freq[x]

means

"All occurrences of x are consecutive."

---------------- EXAMPLE ----------------

nums =

[1, 2, 2, 3, 4, 4, 4, 5]

For 2:

first = 1
last = 2
freq = 2

2 - 1 + 1 = 2

SPECIAL ✓


For 4:

first = 4
last = 6
freq = 3

6 - 4 + 1 = 3

SPECIAL ✓


For 1:

first = 0
last = 0
freq = 1

0 - 0 + 1 = 1

SPECIAL ✓

So answer = 3.

---------------- WHY HASHMAP ----------------

Numbers ki range agar unknown hai
ya bahut large hai,

to fixed-size frequency array
use karna convenient nahi hoga.

unordered_map ki help se
sirf actually present numbers
store hote hain.

Average:

insert/find = O(1)

---------------- TIME COMPLEXITY ----------------

First loop:

O(n)

Second loop:

O(k)

where k = number of unique elements.

Overall:

O(n + k)

Since k <= n:

O(n) average

---------------- SPACE COMPLEXITY ----------------

freq  -> O(k)
first  -> O(k)
last   -> O(k)

Overall:

O(k)

Worst case:

O(n)

---------------- INTERVIEW TRICK ----------------

Agar interviewer pooche:

"How do you know the occurrences are continuous?"

Simply bolo:

"Main first occurrence aur last occurrence ke
beech ki range length compare karta hoon frequency ke saath.
Agar dono equal hain, to us range ki har position par
same element hona compulsory hai, hence all occurrences
are consecutive."
*/