class Solution {
public:
    string removeDigit(string number, char digit) {

        // ans will store the maximum possible string after removing exactly one occurrence of digit
        string ans = "";

        int n = number.size();

        // traverse the string and try removing digit from every position where it occurs
        for (int i = 0; i < n; i++) {

            // only remove if current character matches the given digit
            if (number[i] == digit) {

                // create a new string by skipping index i
                // left part: [0 ... i-1]
                // right part: [i+1 ... end]
                string temp = number.substr(0, i) + number.substr(i + 1);

                // choose the maximum string (lexicographically)
                // since all candidates have same length, lexicographical compare == numerical compare
                if (ans == "" || temp > ans) {
                    ans = temp;
                }
            }
        }

        // return the best possible string
        return ans;
    }
};
