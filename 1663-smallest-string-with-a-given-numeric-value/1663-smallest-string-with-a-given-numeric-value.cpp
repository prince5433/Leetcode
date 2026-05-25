class Solution {
public:
    string getSmallestString(int n, int k) {
        
        /*
        Intuition:
        Lexicographically smallest string chahiye
        jiska total value = k
        (a=1, b=2 ... z=26)

        Sabse chhota string tab banega
        jab left side pe small chars rahe.
        
        So:
        Start with all 'a'
        kyunki 'a' smallest hai.
        */

        string ans(n, 'a');

        /*
        Har 'a' already value 1 de raha.
        Total n value already used.
        */
        k -= n;

        /*
        Extra value right se fill karenge.
        Kyunki right side change karne se
        lexicographical order kam affect hota.
        */
        int i = n - 1;

        while (i >= 0 && k > 0) {

            /*
            Ek char max 25 aur badh sakta
            ('a' -> 'z')
            */
            int add = min(25, k);

            ans[i] += add;   // current char increase
            k -= add;
            i--;
        }

        return ans;
    }
};

/*
Quick Idea:
Start with "aaaa..."
Extra value rightmost chars me fill karo.

Example:
n=3, k=27

Start:
"aaa" = 3
extra = 24

Last char +24
"aay"

TC:
O(n)

SC:
O(n)  // answer string

Pattern:
Greedy
String Construction
*/