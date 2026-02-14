class Solution {
public:

    // dp[idx][tight][cnt]
    // idx   = current digit position
    // tight = restriction flag (1 = restricted, 0 = free)
    // cnt   = how many times digit '1' appeared so far
    int dp[20][2][20];

    int solve(string& s,int idx,int tight,int cnt){

        // Base case:
        // Agar hum last digit tak pahunch gaye,
        // to jitne '1' count hue hain wo return kar do
        if(idx==s.size()) return cnt;


        // Agar ye state already calculate ho chuki hai,
        // to stored answer return kar do (DP memoization)
        if(dp[idx][tight][cnt]!=-1) return dp[idx][tight][cnt];


        // Decide maximum digit allowed at current position
        // Agar tight=1 hai to original number ke digit tak hi ja sakte hain
        // Agar tight=0 hai to freely 0–9 use kar sakte hain
        int limit=(tight==1?s[idx]-'0':9);


        int ans=0;


        // Try all possible digits from 0 to limit
        for(int i=0;i<=limit;i++){

            // Agar current digit '1' hai to count increase karo
            int updatecnt=cnt+(i==1?1:0);


            // Update tight condition
            // tight remains 1 only if:
            // previous tight was 1 AND current digit equals original digit
            // otherwise tight becomes 0 (free state)
            int newtight=(tight&((i==s[idx]-'0')));


            // Move to next digit
            ans+=solve(s,idx+1,newtight,updatecnt);
        }


        // Store result in dp array and return
        return dp[idx][tight][cnt]=ans;
    }


    int countDigitOne(int n) {

        // Convert number into string
        // Digit DP works digit-by-digit using string
        string s = to_string(n);


        // Initialize dp array with -1
        // means no state is calculated yet
        memset(dp, -1, sizeof(dp));


        // Start recursion from:
        // idx=0 → first digit
        // tight=1 → restricted initially
        // cnt=0 → no '1' counted yet
        return solve(s, 0, 1, 0);
    }
};
