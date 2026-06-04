class Solution {
public:

    // Function to count the number of "waves" inside a single number
    int wavy(int x) {

        // convert integer to string so we can compare digits easily
        string s = to_string(x);
        int n = s.size();

        // numbers with less than 3 digits cannot form a wave
        // because a peak/valley needs left + right neighbors
        if (n < 3) return 0;

        int cnt = 0;

        // check each middle digit (i-1, i, i+1)
        for (int i = 1; i < n - 1; i++) {

            // peak condition: s[i] is greater than both neighbors
            if (s[i] > s[i - 1] && s[i] > s[i + 1])
                cnt++;

            // valley condition: s[i] is smaller than both neighbors
            if (s[i] < s[i - 1] && s[i] < s[i + 1])
                cnt++;
        }

        return cnt;  // total waves in number x
    }


    // Count waves for every number in the range [num1, num2]
    int totalWaviness(int num1, int num2) {

        int ans = 0;

        // iterate through all numbers and sum their waviness
        for (int x = num1; x <= num2; x++) {
            ans += wavy(x);
        }

        return ans;
    }
};
