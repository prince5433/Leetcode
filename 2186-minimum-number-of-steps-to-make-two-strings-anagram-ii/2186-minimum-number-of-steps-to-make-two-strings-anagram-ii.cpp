class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> mp1;   // map to store frequency difference of characters

        // Count frequency of characters in string s
        for(char c : s)
            mp1[c]++;

        // Subtract frequency of characters in string t
        for(char c : t)
            mp1[c]--;

        int ans = 0;   // to store total minimum steps (deletions)

        // Sum absolute differences of all character frequencies
        for(auto it : mp1){
            ans += abs(it.second);
        }

        return ans;   // return minimum number of steps
    }
};
