class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        unordered_map<char,int> mp;
        int idx=0;
        for(char ch='a';ch<='z';ch++){
            mp[ch]=idx++;
        }
        int first=0;
        for(char c:firstWord){
            first=first*10+mp[c];
        }
        int second=0;
        for(char c:secondWord){
            second=second*10+mp[c];
        }
        int target=0;
        for(char c:targetWord){
            target=target*10+mp[c];
        }
        return first+second==target;
    }
};