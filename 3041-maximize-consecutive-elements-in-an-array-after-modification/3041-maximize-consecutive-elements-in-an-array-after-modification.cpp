
class Solution {
public:

    // Array ka size.
    int n;

    // memo[i][inc]:
    // Index i se start karke maximum kitne consecutive
    // elements select kar sakte hain.
    //
    // inc = 0 -> Current element ko increment nahi kiya.
    // inc = 1 -> Current element ko increment kiya.
    //
    // -1 means state abhi calculate nahi hui.
    vector<vector<int>> memo;


    // FUNCTION 1: findMethod()
    //
    // Sorted array mein target value search karta hai.
    //
    // start = Search kis index se start karni hai.
    // target = Kaunsi value search karni hai.
    //
    // Value mil gayi toh uska index return karo.
    // Nahi mili toh -1 return karo.
    int findMethod(vector<int>& nums, int start, int target) {

        // Binary Search:
        // start se lekar array ke end tak target search karo.
        //
        // lower_bound first position return karta hai
        // jahan nums[index] >= target.
        int j = lower_bound(nums.begin() + start, nums.end(), target)
                - nums.begin();

        // Check karo ki index valid hai
        // aur exactly target value hi mili hai.
        if(j < n && nums[j] == target) {
            return j;
        }

        // Target nahi mila.
        return -1;
    }


    // FUNCTION 2: solve()
    //
    // i = Current element ka index.
    // inc = Current element ko increment kiya hai ya nahi.
    //
    // Return:
    // Index i se start karke maximum consecutive
    // elements ki length.
    int solve(int i, int inc, vector<int>& nums) {

        // Memoization check:
        // Agar same state pehle calculate ho chuki hai,
        // toh stored answer return kar do.
        if(memo[i][inc] != -1) {
            return memo[i][inc];
        }


        // Current element ki actual selected value.
        //
        // inc = 0 -> nums[i] hi selected value hogi.
        // inc = 1 -> nums[i] + 1 selected value hogi.
        int currval = nums[i] + inc;


        // Current element ko select karna compulsory hai.
        // Isliye minimum length 1 hogi.
        int len = 1;


        // CASE 1:
        //
        // Next consecutive value = currval + 1.
        //
        // Agar nums[j] == currval + 1 mil gaya,
        // toh us element ko increment karne ki zarurat nahi.
        //
        // Isliye next state mein inc = 0 hoga.
        int j = findMethod(nums, i + 1, currval + 1);

        if(j != -1) {

            // Current element + next element ki maximum length.
            len = max(len, 1 + solve(j, 0, nums));
        }


        // CASE 2:
        //
        // Next consecutive value = currval + 1.
        //
        // Is baar hum aisa element search karenge
        // jiska original value currval ho.
        //
        // Us element ko +1 kar denge,
        // toh selected value currval + 1 ban jayegi.
        //
        // Isliye next state mein inc = 1 hoga.
        j = findMethod(nums, i + 1, currval);

        if(j != -1) {

            // Current element + incremented next element.
            len = max(len, 1 + solve(j, 1, nums));
        }


        // Dono possibilities mein se maximum length store karo.
        // Future mein same state aayi toh dobara recursion nahi chalega.
        return memo[i][inc] = len;
    }


    // MAIN FUNCTION
    int maxSelectedElements(vector<int>& nums) {

        n = nums.size();

        // Empty array ka answer 0.
        if(n == 0) return 0;


        // Sorting zaroori hai taaki binary search use kar sakein.
        sort(nums.begin(), nums.end());


        // DP initialization:
        // n rows = n elements.
        // 2 columns = inc ke 2 possible states (0 and 1).
        //
        // Initially sabhi states uncalculated hain.
        memo.assign(n, vector<int>(2, -1));


        // Maximum answer store karenge.
        int result = 1;


        // Har element ko starting element maan kar check karo.
        for(int i = 0; i < n; i++) {

            // Current element ko bina increment kiye start karo.
            int option1 = solve(i, 0, nums);

            // Current element ko increment karke start karo.
            int option2 = solve(i, 1, nums);

            // Dono possibilities mein maximum length lo.
            result = max({result, option1, option2});
        }

        return result;
    }
};


/*
TIME COMPLEXITY:

1. Sorting:
   O(n log n)

2. DP States:
   Total states = n * 2
   = O(n)

3. Each DP state:
   Maximum 2 binary searches.
   Each binary search = O(log n).

   Total DP = O(n log n)

OVERALL TC = O(n log n)


SPACE COMPLEXITY:

Memoization = O(2*n) = O(n)
Recursion Stack = O(n)

OVERALL SC = O(n)
*/
