class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> mp1;
        for(char c:s) mp1[c]++;
        for(char c:t) mp1[c]--;
        int ans=0;
        for(auto it:mp1){
            ans+=abs(it.second);
        }
        return ans;
    }
};