class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        // Pehli Land ride ka minimum finish time
        int min_land = INT_MAX;
        for(int i = 0; i < n; i++){
            min_land = min(min_land, landStartTime[i] + landDuration[i]);
        }
        
        // Pehli Water ride ka minimum finish time
        int min_water = INT_MAX;
        for(int i = 0; i < m; i++){
            // Yahan typo tha, min_water update karna hai
            min_water = min(min_water, waterStartTime[i] + waterDuration[i]); 
        }
        
        // Case 1: Pehle Land, phir Water
        int ans1 = INT_MAX;
        for(int i = 0; i < m; i++){
            // Yahan max aayega kyunki wait time consider karna hai
            ans1 = min(ans1, max(min_land, waterStartTime[i]) + waterDuration[i]);
        }
        
        // Case 2: Pehle Water, phir Land
        int ans2 = INT_MAX;
        for(int i = 0; i < n; i++){
            // Same yahan bhi max aayega
            ans2 = min(ans2, max(min_water, landStartTime[i]) + landDuration[i]);
        }
        
        return min(ans1, ans2);
    }
};