class Solution {
public:
    int largestInteger(int num) {

        string s = to_string(num);   // convert number to string

        vector<char> odd, even;      // store odd digits & even digits separately

        // Separate digits based on parity
        for (char c : s) {
            int digit = c - '0';
            if (digit % 2 == 0)
                even.push_back(c);
            else
                odd.push_back(c);
        }

        // Sort both in descending order
        sort(even.rbegin(), even.rend());
        sort(odd.rbegin(), odd.rend());

        string ans;
        int ei = 0, oi = 0;   // pointers for even & odd vectors

        // Rebuild the number using original parity positions
        for (char c : s) {
            int digit = c - '0';
            if (digit % 2 == 0) {
                ans.push_back(even[ei]);
                ei++;
            } else {
                ans.push_back(odd[oi]);
                oi++;
            }
        }

        return stoi(ans);  // convert back to integer
    }
};
