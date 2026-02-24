class Solution {
public:
    string reverseByType(string s) {
        int n = s.size();

        // -------- First Pass : Reverse Alphabets --------
        int i = 0, j = n - 1;
        while (i < j) {

            // agar left character alphabet nahi hai to aage badho
            if (!isalpha(s[i])) {
                i++;
            }

            // agar right character alphabet nahi hai to piche jao
            else if (!isalpha(s[j])) {
                j--;
            }

            // agar dono alphabet hain to swap karo
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        // -------- Second Pass : Reverse Special Characters --------
        i = 0;
        j = n - 1;

        while (i < j) {

            // agar left character alphabet hai to skip karo
            if (isalpha(s[i])) {
                i++;
            }

            // agar right character alphabet hai to skip karo
            else if (isalpha(s[j])) {
                j--;
            }

            // agar dono special characters hain to swap karo
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};