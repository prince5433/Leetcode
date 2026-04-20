class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;

        // INTUITION:
        // Maximum distance will always involve either:
        // 1) first element (index 0)
        // 2) last element (index n-1)
        // Because they give the largest possible span.

        // Case 1:
        // Fix first element and find the farthest different color from right
        for(int j = n - 1; j >= 0; j--) {
            if(colors[j] != colors[0]) {
                // distance = j - 0
                ans = j;
                break; // first such j from right gives max distance
            }
        }

        // Case 2:
        // Fix last element and find the farthest different color from left
        for(int i = 0; i < n; i++) {
            if(colors[i] != colors[n - 1]) {
                // distance = (n-1) - i
                ans = max(ans, n - i - 1);
                break; // first such i from left gives max distance
            }
        }

        return ans;
    }
};