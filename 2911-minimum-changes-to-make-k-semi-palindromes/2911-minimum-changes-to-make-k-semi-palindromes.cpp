
class Solution {
public:

    // String ki total length.
    int n;

    // Original string ko class variable mein store kar rahe hain
    // taaki getCost() function directly access kar sake.
    string str;

    // costMemo[i][j]:
    // Substring str[i...j] ko beautiful banane ke minimum changes.
    //
    // -1 ka matlab hai ki abhi tak iska answer calculate nahi hua.
    vector<vector<int>> costMemo;

    // solveMemo[start][k]:
    // Index 'start' se string ke end tak ke part ko
    // exactly k beautiful substrings mein divide karne ka
    // minimum total cost.
    //
    // -1 ka matlab hai ki state calculate nahi hui.
    vector<vector<int>> solveMemo;


    // FUNCTION 1: getCost(i, j)
    //
    // Is function ka kaam hai:
    // Substring str[i...j] ko beautiful banane ke liye
    // minimum kitne character changes chahiye.
    int getCost(int i, int j) {

        // Current substring ki length.
        // Example: i = 2, j = 6
        // Length = 6 - 2 + 1 = 5.
        int len = j - i + 1;

        // Initially minimum cost INT_MAX rakhenge.
        // Baad mein valid divisors ke costs se minimum find karenge.
        int mincost = INT_MAX;

        // Memoization check:
        // Agar is substring ka answer pehle calculate ho chuka hai,
        // toh dobara calculation karne ki zarurat nahi.
        if(costMemo[i][j] != -1)
            return costMemo[i][j];


        // Beautiful substring ke liye humein possible divisors check karne hain.
        //
        // d = number of equal-length groups.
        //
        // Example:
        // len = 6
        // Possible d = 1, 2, 3
        //
        // Har group ka size len/d hoga.
        for(int d = 1; d < len; d++) {

            // Agar length completely d se divide nahi hoti,
            // toh equal-sized groups banana possible nahi hai.
            // Isliye is d ko skip kar do.
            if(len % d != 0)
                continue;


            // Current divisor d ke liye required changes.
            int cost = 0;


            // Har group mein ek particular position check karenge.
            //
            // Example:
            // len = 6, d = 2
            //
            // Groups:
            // Group 1: positions 0, 2, 4
            // Group 2: positions 1, 3, 5
            //
            // Isliye group = 0 se d-1 tak chalega.
            for(int group = 0; group < d; group++) {

                // Current group ka starting index.
                //
                // i + group se group ki first position milti hai.
                int l = i + group;

                // Current group ka ending index.
                //
                // Ek group mein len/d elements hain.
                // Isliye last index:
                // l + (len/d - 1) * d
                //
                // IMPORTANT:
                // Tere original code mein yahan (l/d - 1)*d tha.
                // Woh generally correct nahi hai.
                // Correct formula mein len/d use hoga.
                int r = l + (len / d - 1) * d;


                // Ab current group ko palindrome banane ke liye
                // left aur right positions compare karenge.
                //
                // Jab tak left right se chhota hai,
                // tab tak comparison possible hai.
                while(l < r) {

                    // Agar dono characters different hain,
                    // toh palindrome banane ke liye
                    // inmein se kisi ek ko change karna padega.
                    if(str[l] != str[r]) {
                        cost++;
                    }

                    // Left pointer ko aage badhao.
                    l += d;

                    // Right pointer ko peeche lao.
                    r -= d;
                }
            }

            // Current divisor ka cost calculate ho gaya.
            // Ab tak ke minimum cost ke saath compare karo.
            mincost = min(mincost, cost);
        }

        // Answer ko memoization array mein save karo
        // taaki future mein same substring aaye toh direct return kar sakein.
        return costMemo[i][j] = mincost;
    }


    // FUNCTION 2: solve(start, k)
    //
    // start = current index jahan se partitioning start hogi.
    // k = abhi kitne beautiful substrings banane baaki hain.
    //
    // Return:
    // Remaining string ko exactly k parts mein divide karne ka
    // minimum total cost.
    int solve(int start, int k) {

        // BASE CASE:
        // Agar koi substring banana baaki nahi hai,
        // toh poori string consume ho jaani chahiye.
        if(k == 0) {

            // start == n means hum string ke end tak pahunch gaye.
            // Exactly k substrings ban gayi hain.
            if(start == n)
                return 0;

            // Agar characters abhi bhi bach rahe hain,
            // toh valid partition possible nahi hai.
            return INT_MAX;
        }


        // PRUNING:
        // Har beautiful substring ki minimum length 2 honi chahiye.
        //
        // Agar k substrings banani hain,
        // toh minimum 2*k characters required honge.
        //
        // Agar remaining characters isse kam hain,
        // toh partition possible nahi hai.
        if(start + 2 * k > n)
            return INT_MAX;


        // Memoization check:
        // Same start aur k wali state pehle calculate ho chuki hai
        // toh stored answer return kar do.
        if(solveMemo[start][k] != -1)
            return solveMemo[start][k];


        // Initially minimum total cost infinity rakhenge.
        int result = INT_MAX;


        // Current substring ka ending index choose karo.
        //
        // end = start + 1 se start kar rahe hain,
        // kyunki substring ki minimum length 2 honi chahiye.
        //
        // end < n rakha hai taaki remaining part valid rahe.
        for(int end = start + 1; end < n; end++) {

            // Current substring:
            // str[start...end]
            //
            // Is substring ko beautiful banane ka minimum cost.
            //
            // Remaining substring:
            // str[end+1...n-1]
            //
            // Us remaining part ko exactly k-1 parts mein divide karo.
            int remcost = solve(end + 1, k - 1);


            // Agar remaining part ko validly divide nahi kar sakte,
            // toh is partition ko ignore karo.
            //
            // INT_MAX ke saath cost add karne se integer overflow
            // ho sakta hai, isliye pehle check kar rahe hain.
            if(remcost == INT_MAX)
                continue;


            // Current substring ka cost + remaining substrings ka cost.
            //
            // Dono ko add karke minimum total answer update karo.
            result = min(result, getCost(start, end) + remcost);
        }


        // Is state ka minimum answer memoization mein save karo.
        return solveMemo[start][k] = result;
    }


    // MAIN FUNCTION
    int minimumChanges(string s, int k) {

        // Original string ki length.
        n = s.size();

        // String ko class variable mein store karo.
        str = s;


        // solveMemo dimensions:
        // (n+1) rows aur (k+1) columns.
        //
        // solveMemo[start][k] initially -1.
        solveMemo.assign(n + 1, vector<int>(k + 1, -1));


        // costMemo dimensions:
        // (n+1) x (n+1).
        //
        // costMemo[i][j] substring i se j ka minimum cost store karega.
        costMemo.assign(n + 1, vector<int>(n + 1, -1));


        // Index 0 se start karo aur exactly k beautiful substrings banao.
        return solve(0, k);
    }
};


/*
TIME COMPLEXITY:

1. getCost(i, j):
   - Possible divisors check karna: O(n)
   - Har divisor ke liye groups aur characters compare karna.
   - Ek substring ke liye worst-case O(n^2).
   - Total possible substrings O(n^2).
   - Memoization ki wajah se har substring ek baar calculate hoti hai.

   Total = O(n^4) upper bound.

2. solve(start, k):
   - States = O(n * k).
   - Har state mein maximum O(n) end positions check hoti hain.
   - getCost memoized hai.

   DP transitions = O(n^2 * k).

Overall upper bound = O(n^4 + n^2 * k).


SPACE COMPLEXITY:

1. costMemo = O(n^2)
2. solveMemo = O(n * k)
3. Recursion stack = O(n)

Total SC = O(n^2 + n*k).
*/
