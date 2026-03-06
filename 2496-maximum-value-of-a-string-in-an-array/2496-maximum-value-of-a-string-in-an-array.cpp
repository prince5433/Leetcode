class Solution {
public:
    int maximumValue(vector<string>& strs) {
        
        int n = strs.size();                 // total number of strings
        vector<int> ans(n);                  // store computed value for each string
        
        for(int i = 0; i < n; i++){
            
            bool hasAlpha = false;           // flag to check if string contains alphabet
            
            // check each character of the current string
            for(char ch : strs[i]){
                if(isalpha(ch)){             // if alphabet found
                    hasAlpha = true;
                    break;                   // no need to check further
                }
            }
            
            // if string contains any alphabet
            if(hasAlpha){
                ans[i] = strs[i].length();   // value = length of string
            } 
            else{
                ans[i] = stoi(strs[i]);      // value = numeric conversion of string
            }
        }
        
        // return the maximum value among all calculated values
        return *max_element(ans.begin(), ans.end());
    }
};