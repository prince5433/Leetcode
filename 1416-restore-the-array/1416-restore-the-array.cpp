class Solution {
public:

// dp[i] -> number of ways to split string starting from index i
int dp[100003];

int n;

const int MOD = 1e9+7;

int solve(int i, string& s, int k){

    // BASE CASE
    // if we reached end of string, it means we successfully split the whole string
    if(i == n) return 1;

    // numbers with leading zero are not allowed
    // so if current digit is '0' we cannot form any valid number
    if(s[i] == '0') return 0;

    // if already computed, return stored result
    if(dp[i] != -1) return dp[i];

    long long nums = 0; // current number we are forming
    int ways = 0;       // total ways from index i

    /*
    INTUITION

    From index i we try to form numbers:
    s[i..i], s[i..i+1], s[i..i+2] ...

    Example:
    s = "1317"

    i = 0

    possible numbers:
    1
    13
    131
    1317

    For each valid number (<= k)
    we recursively solve the remaining string
    */

    for(int j = i; j < n; j++){

        // build number digit by digit
        nums = nums * 10 + (s[j] - '0');

        // if number exceeds k we stop
        // because adding more digits will only increase it
        if(nums > k) break;

        // choose this split and solve remaining part
        ways = (ways + solve(j+1, s, k)) % MOD;
    }

    // store result in dp to avoid recomputation
    return dp[i] = ways;
}

int numberOfArrays(string s, int k) {

    n = s.size();

    // initialize dp with -1 (not computed)
    memset(dp, -1, sizeof(dp));

    return solve(0, s, k);
}
};