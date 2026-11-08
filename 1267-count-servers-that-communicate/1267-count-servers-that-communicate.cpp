class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int n = grid.size();       // Total rows
        int m = grid[0].size();    // Total columns

        /*
            rowCount[i] = Number of servers in row i.
            colCount[j] = Number of servers in column j.

            Initially, all counts are 0.

            SC: O(N + M)
        */
        vector<int> rowCount(n, 0);
        vector<int> colCount(m, 0);


        /*
            STEP 1: COUNT SERVERS IN EVERY ROW AND COLUMN.

            Traverse the complete grid.

            If grid[i][j] == 1:
            - A server exists at (i,j).
            - Increase the count of its row.
            - Increase the count of its column.

            Outer loop: N iterations.
            Inner loop: M iterations.

            Total grid traversal: O(N * M).

            Each increment operation: O(1).
        */
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1) {

                    // This server belongs to row i.
                    rowCount[i]++;
                    // TC: O(1)

                    // This server belongs to column j.
                    colCount[j]++;
                    // TC: O(1)
                }
            }
        }
        // Total TC: O(N * M)


        int communicate = 0;


        /*
            STEP 2: CHECK WHICH SERVERS CAN COMMUNICATE.

            Traverse the grid again.

            A server can communicate if:
            1. Another server exists in the same row.
               rowCount[i] > 1

            OR

            2. Another server exists in the same column.
               colCount[j] > 1

            Why > 1?

            Because the current server itself is already
            included in rowCount[i] and colCount[j].

            So count > 1 means at least one OTHER server
            exists in that row or column.

            Outer loop: N iterations.
            Inner loop: M iterations.

            Total traversal: O(N * M).
        */
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                // Check only cells containing a server.
                if(grid[i][j] == 1 &&
                   (rowCount[i] > 1 || colCount[j] > 1)) {

                    // This server can communicate with another server.
                    communicate++;
                    // TC: O(1)
                }
            }
        }
        // Total TC: O(N * M)


        // Return total number of communicating servers.
        return communicate;
    }
};


/*
================================================
TIME COMPLEXITY ANALYSIS
================================================

Let:
N = Number of rows
M = Number of columns

1. Creating rowCount and colCount:
   O(N + M)

2. First nested loop:
   N * M cells are visited.
   O(N * M)

3. Second nested loop:
   Again N * M cells are visited.
   O(N * M)

4. Final return:
   O(1)

Total:

O(N + M) + O(N * M) + O(N * M)

= O(N * M)

================================================
SPACE COMPLEXITY ANALYSIS
================================================

1. rowCount array = O(N)
2. colCount array = O(M)
3. Other variables = O(1)

Total:

O(N + M)

================================================
FINAL COMPLEXITIES
================================================

TC: O(N * M)
SC: O(N + M)

================================================
*/