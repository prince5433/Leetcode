class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int total = 0;

        // For every attack except the last one
        // We add the poisoning time, but it can overlap with the next attack
        // So we add the minimum of:
        //   1) Full duration
        //   2) Time gap between two attacks (timeSeries[i+1] - timeSeries[i])
        for(int i = 0; i < n - 1; i++){
            total += min(timeSeries[i + 1] - timeSeries[i], duration);
        }

        // Last attack always adds full duration
        return total + duration;
    }
};
