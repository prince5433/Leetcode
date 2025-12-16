class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {

        // Map to count in how many days a response appears
        map<string,int> mp;

        // Total number of days
        int n = responses.size();

        // Process each day's responses
        for(auto it : responses){

            // Set to avoid counting duplicate responses in the same day
            set<string> seen;

            // Insert all responses of the current day
            for(string str : it){
                seen.insert(str);
            }

            // Increase count for each unique response of the day
            for(auto i : seen){
                mp[i]++;
            }
        }

        // Find the response that appears in maximum days
        string ans = "";
        int maxi = 0;

        for(auto c : mp){
            // Update answer if current response appears more times
            if(c.second > maxi){
                maxi = c.second;
                ans = c.first;
            }
            // No need to handle tie explicitly because:
            // map is sorted and we traverse in lexicographical order
        }

        // Return the most common response
        return ans;
    }
};
