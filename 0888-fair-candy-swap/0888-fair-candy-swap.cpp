class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {

        int suma = 0, sumb = 0;                 // dono arrays ka total sum
        for(int x : aliceSizes) suma += x;      // Alice ka sum
        for(int x : bobSizes) sumb += x;        // Bob ka sum

        int diff = (sumb - suma) / 2;           // y - x = diff (swap condition)

        set<int> st(bobSizes.begin(), bobSizes.end()); // Bob ke elements store for fast lookup

        for(int x : aliceSizes){                // Alice ka har candy size x
            int y = x + diff;                   // required Bob ka candy size y
            if(st.count(y)) return {x, y};      // mil gaya to answer return
        }

        return {};                              // fallback (normally nahi aayega)
    }
};
