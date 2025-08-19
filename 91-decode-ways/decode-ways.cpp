#define ll long long int

class Solution {
public:
vector<ll> dp;
ll f(string&str ,int i){
    if(i<0) return 1;
    if(i==0) return (str[0]!='0');

    if(dp[i]!=-1) return dp[i];
    ll ans=0;
    if(str[i]-'0'>0){
        ans+=f(str,i-1);
    }
    if(str[i-1]-'0'>0 and (str[i-1]-'0')*10+(str[i]-'0')<=26){
        ans+=f(str,i-2);
    }
    return dp[i]=ans;
}
    int numDecodings(string s) {
        int n=s.size();
        dp.resize(n,-1);
         return f(s,n-1);
    }
};