class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        int cnt = 0;

        for(int i = 0; i < m; i++) {

            // Check if current plot is empty
            if(flowerbed[i] == 0) {

                // Check left side:
                // If we are at index 0 OR left plot is 0 (empty)
                bool left = (i == 0) || (flowerbed[i - 1] == 0);

                // Check right side:
                // If we are at last index OR right plot is 0 (empty)
                bool right = (i == m - 1) || (flowerbed[i + 1] == 0);

                // If both left and right conditions allow, we can plant flower here
                if(left && right) {
                    flowerbed[i] = 1; // Plant flower
                    cnt++;            // Increase planted flower count
                }
            }
        }

        // If planted flowers are >= required flowers, return true
        return cnt >= n;
    }
};
