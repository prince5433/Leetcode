class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        
        // Count of Left, Right, and Underscore moves
        int lcount = 0, rcount = 0, dcount = 0;

        // Step 1: Count occurrences
        for(int i = 0; i < n; i++){
            if(moves[i] == 'L') lcount++;      // move left
            else if(moves[i] == 'R') rcount++; // move right
            else dcount++;                     // unknown move '_'
        }

        int ans = 0;

        // Step 2: Decide direction for '_' to maximize distance
        if(lcount == rcount){
            // If both sides equal → no net movement yet
            // Use all '_' in one direction
            ans = dcount;
        }
        else if(rcount < lcount){
            // More left moves → go further left using '_'
            ans = dcount + (lcount - rcount);
        } 
        else {
            // More right moves → go further right using '_'
            ans = dcount + (rcount - lcount);
        }

        return ans;
    }
};