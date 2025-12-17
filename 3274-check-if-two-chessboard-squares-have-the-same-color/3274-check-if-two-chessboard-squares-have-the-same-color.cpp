class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {

        // Convert first coordinate to numeric values
        int c1 = (coordinate1[0] - 'a' + 1) + (coordinate1[1] - '0');

        // Convert second coordinate to numeric values
        int c2 = (coordinate2[0] - 'a' + 1) + (coordinate2[1] - '0');

        // If parity (even/odd) is same → same color
        return (c1 % 2) == (c2 % 2);
    }
};
