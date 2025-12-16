class Solution {
public:
    string sortString(string s) {
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        string ans="";
        int n=s.size();
        while(ans.size()<n){
            for(char ch='a';ch<='z';ch++){
            if(mp[ch]>0){
                ans+=ch;
                mp[ch]--;
            }
        }

         for(char ch='z';ch>='a';ch--){
            if(mp[ch]>0){
                ans+=ch;
                mp[ch]--;
            }
        }
        }
        return ans;
       
    }
};