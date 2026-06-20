class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int i = 0;
        int j = 0;
        int cnt = 1;
        int n = word.size();
        int ans = 0;

        while (j < n) {
            if (j > 0) {
                if (word[j] > word[j - 1]) cnt++;
                else if (word[j] < word[j - 1]) {
                    i = j;
                    cnt = 1;
                }
            }

            if (cnt == 5) {
                ans = max(ans, j - i + 1);
            }

            j++;
        }

        return ans;
    }
};