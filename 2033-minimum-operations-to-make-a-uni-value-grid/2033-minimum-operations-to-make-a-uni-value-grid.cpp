class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        int m = grid.size();       // total rows
        int n = grid[0].size();    // total columns
        
        vector<int> nums;
        
        // poori 2D grid ko ek single array me convert kar rahe hain
        // kyuki hume bas saare numbers chahiye, position se koi matlab nahi
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                nums.push_back(grid[i][j]);
            }
        }

        // median nikalne ke liye sort zaruri hai
        sort(nums.begin(), nums.end());

        // median hi best target hota hai minimum absolute operations ke liye
        int median = nums[nums.size()/2];

        int ops = 0;

        // har number ko median tak lane ki cost calculate karenge
        for(int i = 0; i < nums.size(); i++) {
            
            int diff = abs(nums[i] - median);

            // agar difference x ka multiple nahi hai
            // to is number ko median tak kabhi nahi la sakte
            if(diff % x != 0) return -1;

            // warna diff/x operations lagenge
            ops += diff / x;
        }

        return ops;
    }
};