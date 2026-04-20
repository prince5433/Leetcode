class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;

        // Check from the end: find the farthest index j such that
        // colors[j] != colors[0]
        // This gives distance from first element
        for(int j = n - 1; j >= 0; j--) {
            if(colors[j] != colors[0]) {
                ans = max(ans, j); // distance = j - 0
                break;
            } 
        }

        // Check from the start: find the first index i such that
        // colors[i] != colors[n-1]
        // This gives distance from last element
        for(int i = 0; i < n; i++) {
            if(colors[i] != colors[n-1]) {
                ans = max(ans, n - i - 1); // distance = (n-1) - i
                break;
            }
        }

        return ans;
    }
};