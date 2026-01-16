class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {

        // covered[i] = 1 means point i kisi na kisi car ke interval me covered hai
        vector<int> covered(101, 0);

        // har interval [l, r] ko traverse karo
        for (auto it : nums) {
            int l = it[0];
            int r = it[1];

            // l se r tak saare integer points ko covered mark kar do
            for (int i = l; i <= r; i++) covered[i] = 1;
        }

        int ans = 0;

        // 1 se 100 tak jitne points covered hain unka count
        for (int x = 1; x <= 100; x++) ans += covered[x];

        return ans;
    }
};
