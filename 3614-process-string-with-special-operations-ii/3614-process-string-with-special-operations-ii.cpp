class Solution {
public:
    char processStr(string s, long long k) {
        long long l = 0;

        for (char &ch : s) {
            if (ch == '*') {
                if (l > 0) l--;
            }
            else if (ch == '#') {
                l *= 2;
            }
            else if (ch == '%') {
                // reverse doesn't change length
            }
            else {
                l++;
            }
        }

        if (k >= l) return '.';

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '*') {
                l++;
            }
            else if (s[i] == '#') {
                l /= 2;
                if (k >= l) k -= l;
            }
            else if (s[i] == '%') {
                k = l - k - 1;
            }
            else {
                l--;
                if (k == l) return s[i];
            }
        }

        return '.';
    }
};