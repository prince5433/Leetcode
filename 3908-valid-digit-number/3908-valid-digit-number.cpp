class Solution {
public:
    bool validDigit(int n, int x) {
        string str = to_string(n);      // convert number into string
        string finde = to_string(x);    // convert digit x into string

        // Condition 1:
        // if first digit itself is x, return false
        if(str[0] - '0' == x) return false;

        // Condition 2:
        // if digit x is not present anywhere in number, return false
        if(str.find(finde) == string::npos) return false;

        // both conditions satisfied
        return true;
    }
};