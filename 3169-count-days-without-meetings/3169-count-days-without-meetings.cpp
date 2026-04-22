class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
         // Step 1: Sort intervals based on starting time
        // Default sorting works because vector compares lexicographically
        // First element compare hota hai, agar same ho to second element
        sort(meetings.begin(), meetings.end());
        
        // Result vector to store merged intervals
        vector<vector<int>> result;
        
        // First interval ko directly result me daal do
        result.push_back(meetings[0]);

        // Step 2: Traverse remaining intervals
        for (int i = 1; i < meetings.size(); i++) {
            
            // Check if current interval overlaps with last merged interval
            if (meetings[i][0] <= result.back()[1]) {
                
                // Overlap case:
                // End time ko maximum se update karo
                result.back()[1] = max(result.back()[1], meetings[i][1]);
            
            } else {
                
                // No overlap:
                // Directly new interval add kar do
                result.push_back(meetings[i]);
            }
        }
        int twd=0;
        for(auto it:result){
            int first=it[0];
            int second=it[1];
            twd+=second-first+1;
        }
        return days-twd;
    }
};