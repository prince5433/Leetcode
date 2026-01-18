class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char c){
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }

    int maxVowels(string s, int k) {
        int i=0;          // left pointer of sliding window
        int j=0;          // right pointer of sliding window
        int n=s.size();   // length of string
        int maxc=0;       // maximum vowels found in any window of size k
        int c=0;          // current vowel count in the window

        while(j<n){
            // include current character (s[j]) into the window
            if(isVowel(s[j])){
                c++;
            }

            // when window size becomes exactly k
            if(j-i+1==k){
                // update maximum vowels count
                maxc=max(maxc,c);

                // before sliding window, remove effect of s[i]
                if(isVowel(s[i])){
                    c--;
                }
                i++; // move left pointer forward
            }

            j++; // move right pointer forward
        }

        return maxc;
    }
};
