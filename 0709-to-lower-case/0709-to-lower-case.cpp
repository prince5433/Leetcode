class Solution {
public:
    string toLowerCase(string s) {
       string temp="";
       for(int i=0;i<s.size();i++){
        temp+=tolower(s[i]);
       }
       return temp;
    }
};