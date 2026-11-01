class Solution {
public:
    int solve(vector<int>& nums, int i, int currSum, int target) {

        // BASE CASE:
        // Saare elements process ho chuke hain.
        if(i == nums.size()) {

            // Agar current sum target ke equal hai,
            // toh humein ek valid way mil gaya.
            if(currSum == target)
                return 1;

            // Agar target match nahi hua, toh ye valid way nahi hai.
            return 0;
        }

        // OPTION 1:
        // Current number ke saath '+' sign lagao.
        // Isliye currSum mein nums[i] add karke next index par jao.
        int plus = solve(nums, i + 1, currSum + nums[i], target);

        // OPTION 2:
        // Current number ke saath '-' sign lagao.
        // Isliye currSum se nums[i] subtract karke next index par jao.
        int minus = solve(nums, i + 1, currSum - nums[i], target);

        // Dono choices se jitne valid ways mile,
        // unko add karke total number of ways return karo.
        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        // Index 0 se start karo aur initially sum 0 rakho.
        return solve(nums, 0, 0, target);
    }
};

// TC: O(2^N) — Har element ke liye 2 choices hain.
// SC: O(N) — Recursion stack ki maximum depth N hai.