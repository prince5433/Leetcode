class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(n==0) return 0;
        vector<int> dp(n+1,0);
        dp[0]=1;//empty string
        dp[1]=(s[0]!='0');//first char valid or not
        for(int i=2;i<=n;i++){
            //one digit (last char)
            if(s[i-1]!='0'){
                dp[i]+=dp[i-1];
            }
            //2 digit (last 2 char)
            int two=(s[i-2]-'0')*10+(s[i-1]-'0');
            if(two>=10 && two<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};