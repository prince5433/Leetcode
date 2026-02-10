class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flips = 0;
        int ones = 0;

        for(char c : s){
            if(c == '1'){
                ones++;
            } else {
                flips = min(flips + 1, ones);
            }
        }
        return flips;
    }
};
