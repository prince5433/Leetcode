class Solution {
public:
    // Function to check whether a character is a vowel
    bool isVowel(char c){
        return (c=='a'||c=='A'||c=='e'||c=='E'||
                c=='i'||c=='I'||c=='o'||c=='O'||
                c=='u'||c=='U');
    }

    bool halvesAreAlike(string s) {
        int n = s.size();
        int cnt1 = 0, cnt2 = 0;

        // Count vowels in the first half
        for(int i = 0; i < n/2; i++){
            if(isVowel(s[i])) cnt1++;
        }

        // Count vowels in the second half
        for(int i = n/2; i < n; i++){
            if(isVowel(s[i])) cnt2++;
        }

        // If both halves have equal vowels, return true
        return cnt1 == cnt2;
    }
};
