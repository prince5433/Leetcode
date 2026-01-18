class Solution {
public:
    int longestContinuousSubstring(string s) {
        int cnt = 1;   // current length of continuous substring
        int ans = 1;   // maximum length found so far

        // start from index 1 and compare with previous character
        for(int i = 1; i < s.size(); i++){
            
            // check if current character is exactly next in alphabet
            if(s[i] - s[i-1] == 1){
                cnt++;   // extend current continuous substring
            } 
            else{
                cnt = 1; // reset length since sequence breaks
            }

            // update maximum length
            ans = max(ans, cnt);
        }

        return ans; // return longest continuous substring length
    }
};
