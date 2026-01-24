class Solution {
public:
    int minimumMoves(string s) {

        int n = s.size();   // string length
        int moves = 0;      // total moves count

        // left to right traverse
        for (int i = 0; i < n; i++) {

            // agar current character 'X' mila
            if (s[i] == 'X') {

                // ek move karna padega (kyuki i ko cover karna zaroori hai)
                moves++;

                // ek move me i, i+1, i+2 teeno positions 'O' ban jaati hain
                // so next check direct i+3 se start karo
                i += 2;
            }
        }

        // minimum moves return
        return moves;
    }
};
