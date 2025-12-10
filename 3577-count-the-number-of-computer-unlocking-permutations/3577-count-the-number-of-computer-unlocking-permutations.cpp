class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        static const int MOD = 1000000007;
        int n = complexity.size();

        // To unlock any computer i > 0, we must use a previously unlocked computer j < i
        // such that complexity[j] < complexity[i].
        //
        // Since only computer 0 is initially unlocked,
        // EVERY computer i > 0 must satisfy:
        //      complexity[i] > complexity[0]
        //
        // If any computer has complexity <= complexity[0], it can never be unlocked.
        for(int i = 1; i < n; i++){
            if (complexity[i] <= complexity[0]) {
                return 0;   // impossible to unlock
            }
        }

        // If all computers are unlockable, then the number of valid unlocking orders
        // is simply (n-1)! because computers 1..n-1 can be unlocked in ANY order.
        long long ans = 1;
        for(int i = 1; i <= n - 1; i++){
            ans = (ans * i) % MOD;   // factorial with modulo
        }

        return ans;  // return (n-1)! % MOD
    }
};
