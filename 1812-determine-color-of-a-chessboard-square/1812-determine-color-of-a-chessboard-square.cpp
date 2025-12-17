class Solution {
public:
    bool squareIsWhite(string coordinates) {

        // Convert column letter to number (a=1, b=2, ..., h=8)
        // Convert row character to integer
        // Add both to get parity
        int c1 = (coordinates[0] - 'a' + 1) + (coordinates[1] - '0');

        // If sum is odd → square is white
        return (c1 % 2) != 0;
    }
};
