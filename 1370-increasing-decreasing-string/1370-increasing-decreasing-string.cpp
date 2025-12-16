class Solution {
public:
    string sortString(string s) {

        // Store frequency of each character
        unordered_map<char,int> mp;
        for(char c : s){
            mp[c]++;
        }

        string ans = "";
        int n = s.size();

        // Keep forming answer until all characters are used
        while(ans.size() < n){

            // Step 1: pick characters from 'a' to 'z'
            for(char ch = 'a'; ch <= 'z'; ch++){
                if(mp[ch] > 0){
                    ans += ch;   // add character to answer
                    mp[ch]--;    // decrease its frequency
                }
            }

            // Step 2: pick characters from 'z' to 'a'
            for(char ch = 'z'; ch >= 'a'; ch--){
                if(mp[ch] > 0){
                    ans += ch;   // add character to answer
                    mp[ch]--;    // decrease its frequency
                }
            }
        }

        // Final sorted string
        return ans;
    }
};
