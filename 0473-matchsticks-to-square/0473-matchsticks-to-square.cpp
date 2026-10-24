class Solution {
public:
    bool f(vector<int>& nums, int idx,
           vector<int>& sides, int target) {

        // BASE CASE:
        // Agar saari matchsticks place ho chuki hain,
        // toh humne har stick ko kisi na kisi side par rakh diya.
        // Har side ki length target se zyada nahi ho sakti.
        // Total length = 4 * target hai, isliye saari sticks
        // place hone par chaaron sides ki length exactly target hogi.
        if (idx == nums.size()) {
            return true;
        }

        // Current matchstick nums[idx] ko 4 sides mein
        // se kisi ek side par rakhne ki koshish karenge.
        for (int i = 0; i < 4; i++) {

            // Agar current stick add karne se side ki length
            // target se zyada ho jayegi, toh yeh choice invalid hai.
            // Isliye aisi side par stick nahi rakh sakte.
            if (sides[i] + nums[idx] <= target) {

                // CHOOSE:
                // Current matchstick ko side i par rakh diya.
                // Ab side i ki length update ho jayegi.
                sides[i] += nums[idx];

                // EXPLORE:
                // Ab next matchstick ko place karne ki koshish karo.
                // Agar aage ki saari sticks successfully place ho gayin,
                // toh square ban sakta hai, isliye true return karo.
                if (f(nums, idx + 1, sides, target)) {
                    return true;
                }

                // UNDO / BACKTRACK:
                // Agar yeh choice aage jaakar fail ho gayi,
                // toh current stick ko side i se hata do.
                // Isse side ki length apni purani value par aa jayegi.
                // Ab isi stick ko kisi doosri side par try kar sakte hain.
                sides[i] -= nums[idx];
            }

            // Agar side i par stick rakhna possible nahi tha,
            // ya wahan rakhne se aage solution nahi mila,
            // toh loop next side ko try karega.
        }

        // Agar current stick ko kisi bhi side par rakhkar
        // valid square nahi bana, toh current path fail hai.
        // Parent recursive call ab apni previous choice undo karegi.
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {

        // Step 1: Sabhi matchsticks ki total length calculate karo.
        int sum = 0;
        for (int x : matchsticks) {
            sum += x;
        }

        // Step 2: Square ki 4 equal sides hoti hain.
        // Agar total length 4 se divisible nahi hai,
        // toh 4 equal integer-length sides banana impossible hai.
        if (matchsticks.size() < 4 || sum % 4 != 0) {
            return false;
        }

        // Har side ki required length.
        int target = sum / 4;

        // Agar sabse badi stick hi target se badi hai,
        // toh woh kisi bhi side mein fit nahi ho sakti.
        // Isliye recursion chalane ki zaroorat nahi.
        sort(matchsticks.rbegin(), matchsticks.rend());

        if (matchsticks[0] > target) {
            return false;
        }

        // sides[i] batata hai ki side i par abhi tak
        // kitni total matchstick length place ki gayi hai.
        // Starting mein chaaron sides empty hain.
        vector<int> sides(4, 0);

        // idx = 0 se pehli matchstick place karna shuru karo.
        // Har recursive call mein next matchstick process hogi.
        return f(matchsticks, 0, sides, target);
    }
};

/*
TIME COMPLEXITY:
O(4^N) worst-case upper bound, kyunki har matchstick ke liye
maximum 4 sides try ho sakti hain. Sorting ka extra cost O(N log N) hai.

SPACE COMPLEXITY:
O(N) recursion stack, kyunki maximum N recursive calls ho sakti hain.
4 sides store karne mein O(1) extra space lagti hai.
*/