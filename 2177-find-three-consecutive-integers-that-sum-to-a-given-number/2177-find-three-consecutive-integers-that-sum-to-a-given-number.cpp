class Solution {
public:
    vector<long long> sumOfThree(long long num) {

        // Vector to store the result
        vector<long long> ans;

        // If num is divisible by 3, then it can be written
        // as the sum of three consecutive integers
        if (num % 3 == 0) {

            // Middle number of the three consecutive numbers
            long long x = num / 3;

            // Push the three consecutive numbers
            ans.push_back(x - 1);
            ans.push_back(x);
            ans.push_back(x + 1);

            // Return the result
            return ans;
        }

        // If not divisible by 3, return empty vector
        return ans;
    }
};
