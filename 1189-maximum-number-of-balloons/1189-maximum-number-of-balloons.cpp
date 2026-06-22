class Solution {
public:
    int maxNumberOfBalloons(string text) {

        /*
        Intuition:

        To form one "balloon",

        Required characters:

        b -> 1
        a -> 1
        l -> 2
        o -> 2
        n -> 1

        Count frequency of all characters.

        Then find how many complete
        "balloon" words can be formed.
        */

        unordered_map<char, int> mp;

        // Count frequency of every character
        for (char c : text)
            mp[c]++;

        /*
        'l' and 'o' are needed twice
        in one balloon.

        So divide their frequencies by 2.
        */
        mp['l'] /= 2;
        mp['o'] /= 2;

        /*
        The limiting character
        determines answer.

        Example:

        b=5
        a=4
        l=3
        o=2
        n=6

        Answer = 2
        */
        return min({mp['b'], mp['a'], mp['l'], mp['o'], mp['n']});
    }
};

/*
---------------- QUICK INTUITION ----------------

Word:

"balloon"

Character Requirements:

b -> 1

a -> 1

l -> 2

o -> 2

n -> 1

------------------------------------------------

Example:

text = "loonbalxballpoon"

Frequencies:

b = 2
a = 2
l = 4
o = 4
n = 2

After dividing:

l = 2
o = 2

Answer:

min(2,2,2,2,2)

= 2

------------------------------------------------

Why min() ?

To make one balloon,
all required characters
must be available.

The character available
in minimum quantity
becomes the bottleneck.

------------------------------------------------

Dry Run

text = "balloonball"

Counts:

b = 2
a = 2
l = 4
o = 2
n = 1

After:

l = 2
o = 1

Answer:

min(2,2,2,1,1)

= 1

------------------------------------------------

TC:

Frequency Count:
O(n)

min() check:
O(1)

Total:
O(n)

------------------------------------------------

SC:

HashMap stores at most
26 lowercase characters.

O(1)

------------------------------------------------

Pattern:

Hashing
Frequency Counting
Greedy Observation
*/