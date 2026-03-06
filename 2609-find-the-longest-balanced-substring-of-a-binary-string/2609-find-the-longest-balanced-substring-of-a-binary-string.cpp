class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n=s.size();
        int i=0;
        int ans=0;
        while(i<n){
            int cz=0;
            int co=0;
            while(i<n && s[i]=='0'){
                cz++;
                i++;
            }
              while(i<n && s[i]=='1'){
                co++;
                i++;
            }
            ans=max(ans,2*min(cz,co));
        }
        return ans;
    }
};