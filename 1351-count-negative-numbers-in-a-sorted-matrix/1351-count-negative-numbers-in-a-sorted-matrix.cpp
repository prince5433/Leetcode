class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int n = grid.size();        // number of rows
        int m = grid[0].size();     // number of columns

        int ans = 0;                // total negative elements ka count

        // Har row par iterate kar rahe hain
        for (int i = 0; i < n; i++) {

            // Binary Search lagayenge kyunki har row sorted hai
            int lo = 0;
            int hi = m - 1;

            // fneg = first negative element ka index
            // agar koi negative na mile to fneg = m rahega
            int fneg = m;

            // Binary Search to find first negative number
            while (lo <= hi) {

                int mid = lo + (hi - lo) / 2;

                // agar mid par value negative hai
                if (grid[i][mid] < 0) {
                    fneg = mid;      // first negative ka index update
                    hi = mid - 1;    // aur left side check karo
                } 
                else {
                    // value positive/zero hai, to right side jao
                    lo = mid + 1;
                }
            }

            // is row me negatives = total columns - first negative index
            ans += m - fneg;
        }

        // total negative elements in whole grid
        return ans;
    }
};
