class Solution {
public:
    vector<string> createGrid(int m, int n) {

        /*
        Intuition:

        Initially entire grid
        is filled with '#'.

        Then:

        1. First row -> '.'
        2. Last column -> '.'

        Remaining cells stay '#'.
        */

        // Create m x n grid filled with '#'
        vector<vector<char>> grid(
            m,
            vector<char>(n, '#')
        );

        /*
        Make first row '.'

        Example:

        . . . . .
        */
        for(int i = 0; i < n; i++) {

            grid[0][i] = '.';
        }

        /*
        Make last column '.'

        Example:

              .
              .
              .
              .
        */
        for(int i = 0; i < m; i++) {

            grid[i][n - 1] = '.';
        }

        vector<string> ans;

        /*
        Convert 2D char grid
        into vector<string>.
        */
        for(int i = 0; i < m; i++) {

            string row = "";

            for(int j = 0; j < n; j++) {

                row += grid[i][j];
            }

            ans.push_back(row);
        }

        return ans;
    }
};

/*
---------------- QUICK INTUITION ----------------

Example:

m = 4
n = 5

Initially:

#####
#####
#####
#####

--------------------------------

First Row = '.'

.....
#####
#####
#####

--------------------------------

Last Column = '.'

.....
####.
####.
####.

--------------------------------

Final Answer:

[
".....",
"####.",
"####.",
"####."
]

------------------------------------------------

Why Use vector<vector<char>> ?

Easy to modify
individual cells.

Later convert to:

vector<string>

as required output format.

------------------------------------------------

TC:

Create Grid:
O(m*n)

Convert Grid:
O(m*n)

Total:
O(m*n)

------------------------------------------------

SC:

Grid Storage:
O(m*n)

Answer:
O(m*n)

Total:
O(m*n)

------------------------------------------------

Pattern:

Matrix Construction
Simulation
Grid Manipulation
*/