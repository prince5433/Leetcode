class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int l = 0;
        int maxi = 0;
        map<char,int> mp;

        for(int r = 0; r < n; r++){
            mp[s[r]]++;                      // add current character to window

            while(mp[s[r]] > 2){             // if any character appears more than 2 times
                mp[s[l]]--;                  // remove left character from window
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);          // erase if frequency becomes zero
                }
                l++;                          // shrink window from left
            }

            maxi = max(maxi, r - l + 1);     // update maximum valid window size
        }

        return maxi;
    }
};
