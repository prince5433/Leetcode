class Solution {
public:
    int countAsterisks(string s) {
        int pipe=0;
        int ast=0;
        for(char c:s){
            if(c=='|') pipe++;
            if(c=='*' && pipe%2==0) ast++;
        }
        return ast;
    }
};