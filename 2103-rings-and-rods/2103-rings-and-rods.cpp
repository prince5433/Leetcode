class Solution {
public:
    int countPoints(string rings) {

        int m = rings.size();

        // Map: rod number -> set of colors present on that rod
        unordered_map<char, unordered_set<char>> mp;

        // rings string ko 2-2 ke pair me process kar rahe hain
        // even index = color, odd index = rod number
        for(int i = 1; i < m; i += 2) {
            char rod = rings[i];       // rod number (0–9)
            char color = rings[i - 1]; // color (R, G, B)

            mp[rod].insert(color);     // color ko rod ke set me daal diya
        }

        int cnt = 0;

        // Har rod check kar rahe hain
        for(auto &it : mp) {

            // Agar rod par R, G aur B teeno present hain
            if(it.second.count('R') &&
               it.second.count('G') &&
               it.second.count('B')) {

                cnt++;   // valid rod mil gaya
            }
        }

        return cnt;
    }
};
