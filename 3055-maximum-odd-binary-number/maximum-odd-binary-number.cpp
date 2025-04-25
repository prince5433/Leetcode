class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        string ans ="";
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') count++;
        }
        int zeroc=n-count;
        //for odd lsb me 1 hona hi chahiye
        for(int i=0;i<count-1;i++) ans+='1';//sare 1 except 1 aage rkho
        for(int i=0;i<zeroc;i++) ans+='0';//bich me sare zeroes dal do
        ans+='1';//last me ek one dal do for making it one
        return ans;
    }
};