class Solution {
public:
    int vowelConsonantScore(string s) {
        int vowel = 0, cons = 0;
        for(char c : s) {
            if(c >= 'a' && c <= 'z') {
                if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') vowel++;
                else cons++;
            }
        }
        if(cons > 0) return vowel / cons;
        return 0;
    }
};
