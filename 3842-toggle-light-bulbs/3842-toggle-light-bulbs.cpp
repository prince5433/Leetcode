class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {

        // Vector to store bulbs which remain ON (odd toggles)
        vector<int> ans;

        // map to store frequency of each bulb number
        // key   -> bulb number
        // value -> number of times toggled
        map<int,int> mp;

        // Count how many times each bulb is toggled
        for(int num : bulbs)
            mp[num]++;

        // Traverse the map
        for(auto it : mp){

            // If toggled odd number of times,
            // bulb will remain ON
            if(it.second % 2 != 0){

                // Store bulb number in answer
                ans.push_back(it.first);
            }
        }

        // Return list of bulbs that remain ON
        return ans;
    }
};
