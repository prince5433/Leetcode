class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
        string temp = "";  // final result string
        
        int n = words.size();  // number of words
        
        for(string word : words){  // iterate over each word
            
            int sum = 0;  // stores total weight of characters in the word
            
            for(char ch : word){  
                // convert character to index
                // 'a' -> 0, 'b' -> 1, ..., 'z' -> 25
                sum += weights[ch - 'a'];
            }
            
            int idx = sum % 26;  // take modulo to map result within 0–25
            
            // reverse alphabet mapping
            // 0 -> z, 1 -> y, 2 -> x ...
            temp += ('z' - idx);
        }
        
        return temp;  // return final mapped string
    }
};