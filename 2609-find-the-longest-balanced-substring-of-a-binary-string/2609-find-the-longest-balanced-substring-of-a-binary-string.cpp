class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size();
        int i = 0;
        int ans = 0;

        while(i < n){
            int cz = 0;
            int co = 0;

            // count consecutive 0s
            while(i < n && s[i] == '0'){
                cz++;
                i++;
            }

            // count consecutive 1s after the 0s
            while(i < n && s[i] == '1'){
                co++;
                i++;
            }

            // balanced substring length = 2 * min(zeros, ones)
            ans = max(ans, 2 * min(cz, co));
        }

        return ans;
    }
};