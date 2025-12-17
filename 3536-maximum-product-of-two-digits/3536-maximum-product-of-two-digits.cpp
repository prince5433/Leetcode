class Solution {
public:
    int maxProduct(int n) {

        // Convert integer n into a string so we can access each digit easily
        string s = to_string(n);

        // Sort the digits in ascending order
        sort(s.begin(), s.end());

        // Store the total number of digits
        int m = s.size();

        // Convert the largest digit (last char) from char to int
        int a = s[m-1] - '0';

        // Convert the second largest digit from char to int
        int b = s[m-2] - '0';

        // Return the product of the two largest digits
        return a * b;
    }
};
