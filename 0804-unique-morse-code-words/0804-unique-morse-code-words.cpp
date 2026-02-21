class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        // Morse code mapping for each letter from 'a' to 'z'
        // Index 0 -> 'a', Index 1 -> 'b', ..., Index 25 -> 'z'
        vector<string> morse = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
            "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
            "..-","...-",".--","-..-","-.--","--.."
        };
        
        // set is used to store unique Morse transformations
        // duplicate automatically ignore ho jayenge
        set<string> st;
        
        // iterate over each word
        for(string word : words) {
            
            // temp string to store Morse transformation of current word
            string temp = "";
            
            // iterate over each character of word
            for(char ch : word) {
                
                // find Morse code using index (ch - 'a')
                // example: 'c' - 'a' = 2 -> morse[2] = "-.-."
                temp += morse[ch - 'a'];
            }
            
            // insert transformation into set
            st.insert(temp);
        }
        
        // number of unique transformations is the size of set
        return st.size();
    }
};