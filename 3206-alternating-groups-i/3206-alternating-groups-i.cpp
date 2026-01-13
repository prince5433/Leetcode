class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();          // total number of colors
        int cnt = 0;                    // count of valid alternating groups

        // check each index as start of a group of size 3 (circular)
        for (int i = 0; i < n; i++) {
            int a = colors[i];                  // first element
            int b = colors[(i + 1) % n];        // second element (circular)
            int c = colors[(i + 2) % n];        // third element (circular)

            // valid alternating group if adjacent colors differ
            if (a != b && b != c)
                cnt++;
        }

        return cnt;                     // total alternating groups
    }
};
