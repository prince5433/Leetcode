class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        // Step 1: Sort meetings based on start time
        // This helps in merging overlapping intervals easily
        sort(meetings.begin(), meetings.end());
        
        // Store merged intervals
        vector<vector<int>> result;
        
        // Add first meeting as starting point
        result.push_back(meetings[0]);

        // Step 2: Merge overlapping intervals
        for (int i = 1; i < meetings.size(); i++) {
            
            // If current meeting overlaps with last merged meeting
            if (meetings[i][0] <= result.back()[1]) {
                
                // Merge by extending the end time
                result.back()[1] = max(result.back()[1], meetings[i][1]);
            
            } else {
                // No overlap → add as a new interval
                result.push_back(meetings[i]);
            }
        }

        // Step 3: Calculate total occupied days (meeting days)
        int twd = 0; // total working days occupied by meetings
        
        for (auto it : result) {
            int first = it[0];
            int second = it[1];
            
            // +1 because intervals are inclusive
            twd += (second - first + 1);
        }

        // Step 4: Free days = total days - occupied days
        return days - twd;
    }
};