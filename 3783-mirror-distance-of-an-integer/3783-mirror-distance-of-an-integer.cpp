class Solution {
public:
    int mirrorDistance(int n) {
        // Convert the integer n into a string
        string temp = to_string(n);

        // Reverse the string to get the mirror of the number
        reverse(temp.begin(), temp.end());

        // Convert the reversed string back into an integer
        int m = stoi(temp);

        // Return the absolute difference between original number and its mirror
        return abs(n - m);
    }
};
