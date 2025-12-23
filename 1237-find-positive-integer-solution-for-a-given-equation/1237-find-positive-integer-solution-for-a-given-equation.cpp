class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {

        vector<vector<int>> ans;   // saare valid (x, y) pairs store karne ke liye

        int x = 1;                 // x ko minimum value se start kiya
        int y = 1000;              // y ko maximum value se start kiya (constraint)

        // jab tak x aur y valid range me hain
        while (x <= 1000 && y >= 1) {

            int val = customfunction.f(x, y); // current f(x, y) calculate karo

            if (val == z) {
                // exact value mil gayi
                ans.push_back({x, y}); // answer me store karo

                x++;   // next possible x try karo
                y--;   // next possible y try karo
            }
            else if (val < z) {
                // value chhoti hai → x badhane se f(x,y) badega
                x++;
            }
            else {
                // value badi hai → y ghatane se f(x,y) kam hoga
                y--;
            }
        }

        return ans;   // saare valid pairs return karo
    }
};
