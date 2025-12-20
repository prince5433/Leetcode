class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int n = strs.size();        // number of rows (strings)
        int m = strs[0].size();     // number of columns (length of each string)

        int cnt = 0;                // count of columns to delete

        // loop through each column
        for (int col = 0; col < m; col++) {

            // check current column row by row
            for (int row = 0; row < n - 1; row++) {

                // agar upar wali string ka character
                // neeche wali string ke character se bada ho
                // matlab column sorted nahi hai
                if (strs[row][col] > strs[row + 1][col]) {

                    cnt++;          // is column ko delete karna padega
                    break;          // ek baar mil gaya, aage check nahi karna
                }
            }
        }

        return cnt;                 // total columns to delete
    }
};
