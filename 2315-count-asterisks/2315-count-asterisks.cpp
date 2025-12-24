class Solution {
public:
    int countAsterisks(string s) {
        int pipe = 0;   // counts how many '|' pipes we have seen
        int ast = 0;    // counts valid '*' asterisks

        for (char c : s) {
            // If current character is '|', increase pipe count
            if (c == '|') 
                pipe++;

            // Count '*' only when we are OUTSIDE pipes
            // pipe % 2 == 0 → outside
            // pipe % 2 == 1 → inside
            if (c == '*' && pipe % 2 == 0) 
                ast++;
        }

        return ast;     // return total valid asterisks
    }
};
