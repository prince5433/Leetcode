class Solution {
public:

    // function to check whether current position
    // is inside the grid or not
    bool isValid(int i, int j, int n) {

        if (i >= 0 && j >= 0 && i < n && j < n)
            return true;

        return false;
    }

    vector<int> executeInstructions(int n,
                                    vector<int>& startPos,
                                    string s) {

        int m = s.size();

        // stores answer for every suffix
        vector<int> ans;

        // Intuition:
        // For every starting index k,
        // start robot again from startPos
        // and simulate all instructions from k -> end

        for (int k = 0; k < m; k++) {

            // initial robot position
            int i = startPos[0];
            int j = startPos[1];

            // counts valid moves
            int steps = 0;

            // execute instructions from current suffix
            for (int idx = k; idx < m; idx++) {

                char ch = s[idx];

                // move robot according to instruction
                if (ch == 'R')
                    j++;

                else if (ch == 'L')
                    j--;

                else if (ch == 'U')
                    i--;

                else
                    i++;

                // if robot goes outside grid
                // stop execution
                if (!isValid(i, j, n)) {
                    break;
                }

                // valid move completed
                steps++;
            }

            // store answer for current suffix
            ans.push_back(steps);
        }

        return ans;
    }
};