class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        
        int fp = 0;   // first player total score
        int sp = 0;   // second player total score
        
        bool active = true;  // true = first player active
                             // false = second player active
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            
            // Rule 1: If current game's points are odd,
            // swap active and inactive players
            if(nums[i] % 2 == 1){
                active = !active;
            }
            
            // Rule 2: Every 6th game (indices 5, 11, 17, ...)
            // swap active and inactive players
            if(i % 6 == 5)
                active = !active;

            // Active player gains points
            if(active){
                fp += nums[i];
            } else {
                sp += nums[i];
            }
        }
        
        // Return score difference
        return fp - sp;
    }
};