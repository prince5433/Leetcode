class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // Step 1: Sort intervals based on starting time
        // Default sorting works because vector compares lexicographically
        // First element compare hota hai, agar same ho to second element
        sort(intervals.begin(), intervals.end());
        
        // Result vector to store merged intervals
        vector<vector<int>> result;
        
        // First interval ko directly result me daal do
        result.push_back(intervals[0]);

        // Step 2: Traverse remaining intervals
        for (int i = 1; i < intervals.size(); i++) {
            
            // Check if current interval overlaps with last merged interval
            if (intervals[i][0] <= result.back()[1]) {
                
                // Overlap case:
                // End time ko maximum se update karo
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            
            } else {
                
                // No overlap:
                // Directly new interval add kar do
                result.push_back(intervals[i]);
            }
        }
        
        // Final merged intervals return karo
        return result;
    }
};