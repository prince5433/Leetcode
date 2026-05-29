class Solution {
public:

    bool ispalindrome(int i, int j, string& s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int dp[2005];
    int solve(int i, string& s){
        if(i == s.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;
        for(int j = i; j < s.size(); j++){
           if(ispalindrome(i, j, s)){
                ans = min(ans, 1 + solve(j+1, s));
           }
        }

        return dp[i] = ans;
    }
    int minCut(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, s) - 1;

    }
};