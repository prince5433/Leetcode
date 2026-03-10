class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {

        // rows[i] → row i ka score track karega
        // cols[j] → column j ka score track karega
        vector<int> rows(3, 0), cols(3, 0);

        // diagonals ke liye alag variables
        int diag = 0, antiDiag = 0;

        int n = moves.size();

        // har move ko process karte hain
        for (int i = 0; i < n; i++) {

            int r = moves[i][0];   // row index
            int c = moves[i][1];   // column index

            // Player A ko +1 aur Player B ko -1 value dete hain
            int val = (i % 2 == 0) ? 1 : -1;

            // row aur column ka score update
            rows[r] += val;
            cols[c] += val;

            // agar move main diagonal par hai
            if (r == c)
                diag += val;

            // agar move anti-diagonal par hai
            if (r + c == 2)
                antiDiag += val;

            // agar kisi row, column ya diagonal ka absolute sum 3 ho jaye
            // iska matlab ek hi player ne tino cells fill kar diye
            if (abs(rows[r]) == 3 || abs(cols[c]) == 3 ||
                abs(diag) == 3 || abs(antiDiag) == 3) {

                // val = 1 → player A
                // val = -1 → player B
                return (val == 1) ? "A" : "B";
            }
        }

        // agar 9 moves ho chuke aur koi winner nahi
        if (n == 9)
            return "Draw";

        // warna game abhi chal raha hai
        return "Pending";
    }
};