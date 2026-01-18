class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);   // convert number into string
        int n = s.size();            // length of string
        int cnt = 0;                 // count of valid substrings
        int i = 0, j = 0;            // sliding window pointers
        string temp = "";            // stores current window substring

        while (j < n) {
            // add current character to the window
            temp += s[j];

            // when window size becomes exactly k
            if (j - i + 1 == k) {
                int ac = stoi(temp); // convert substring into integer

                // avoid division by zero
                if (ac != 0) {
                    // check if substring divides the original number
                    if (num % ac == 0) cnt++;
                }

                // slide the window: remove first character using substring
                temp = temp.substr(1);

                // move left pointer forward
                i++;
            }

            // move right pointer forward
            j++;
        }

        return cnt; // return total count
    }
};
