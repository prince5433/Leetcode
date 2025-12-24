class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string temp="";
        for(string word:words){
            temp+=word[0];
        }
        return temp==s;
    }
};