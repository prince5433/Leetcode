class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

        // Map to store frequency of each word from both sentences
        unordered_map<string,int> mp1;

        // Stringstream to break first sentence into words
        stringstream ss(s1);
        string temp;

        // Count words from s1
        while (ss >> temp) {
            mp1[temp]++;
        }

        // Stringstream to break second sentence into words
        stringstream sp(s2);

        // Count words from s2
        while (sp >> temp) {
            mp1[temp]++;
        }

        // Vector to store uncommon words
        vector<string> ans;

        // A word is uncommon if it appears exactly once in total
        for (auto& it : mp1) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }

        // Return list of uncommon words
        return ans;
    }
};
