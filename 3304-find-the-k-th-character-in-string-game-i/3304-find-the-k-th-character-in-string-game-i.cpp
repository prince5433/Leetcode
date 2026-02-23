class Solution {
public:
    char kthCharacter(int k) {
        
        string word = "a";   // initial string given in problem
        
        // Keep performing operation until length >= k
        while(word.size() < k){
            
            string temp = "";   // to store shifted version of current word
            
            // Generate new string by shifting each character to next alphabet
            for(char c : word){
                if(c == 'z') 
                    temp += 'a';     // wrap around if character is 'z'
                else 
                    temp += (c + 1); // next alphabet character
            }
            
            // Append generated string to original word
            word += temp;
        }
        
        // Return k-th character (0-based indexing)
        return word[k - 1];
    }
};