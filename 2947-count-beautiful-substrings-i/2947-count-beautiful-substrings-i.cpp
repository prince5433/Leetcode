class Solution {
public:

    // Function to check whether a character is a vowel
    bool isVowel(char c){
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }

    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;

        // Try all possible starting points of substring
        for(int i = 0; i < n; i++){
            int v = 0; // vowel count in current substring
            int c = 0; // consonant count in current substring

            // Extend substring ending at j
            for(int j = i; j < n; j++){
                char ch = s[j];

                // Count vowel or consonant
                if(isVowel(ch)) 
                    v++;
                else 
                    c++;

                // A substring is considered only if vowels = consonants
                if(v == c){
                    long long prod = 1LL * v * c;

                    // Check if product is divisible by k
                    if(prod % k == 0) 
                        ans++;
                }
            }
        }

        // Return total beautiful substrings
        return ans;
    }
};
