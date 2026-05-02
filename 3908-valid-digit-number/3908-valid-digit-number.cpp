class Solution {
public:
    bool validDigit(int n, int x) {
        string str=to_string(n);
        string finde=to_string(x);
        for(int i=0;i<str.length();i++){
            if(str[0]-'0'==x ) return false;
            if(str.find(finde)==string::npos) return false;
        }
        return true;
    }
};