class Solution {
public:
    int minimumChairs(string s) {
        
        // cnt → current number of people inside the room
        int cnt = 0;
        
        // ans → maximum number of people present at any time
        // this directly represents minimum chairs required
        int ans = INT_MIN;

        // Traverse the event string
        for(int i = 0; i < s.size(); i++) {
            
            // If person enters → increase count
            if(s[i] == 'E') 
                cnt++;
            else 
                // If person leaves → decrease count
                cnt--;
            
            // Track maximum people at any moment
            // because we need chairs for peak occupancy
            ans = max(ans, cnt);
        }

        // Return the maximum number of people present at once
        return ans;
    }
};