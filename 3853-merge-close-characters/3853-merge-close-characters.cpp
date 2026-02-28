class Solution {
public:
    string mergeCharacters(string s, int k) {
        
        while (true) {
            
            bool merged = false;   // check karega ki merge hua ya nahi
            
            for (int i = 0; i < s.size(); i++) {
                
                for (int j = i + 1; j < s.size(); j++) {
                    
                    if (s[i] == s[j] && j - i <= k) {
                        
                        s.erase(j, 1);   // right character delete
                        merged = true;
                        break;          // ek hi merge allowed
                    }
                }
                
                if (merged) break;   // restart from beginning
            }
            
            if (!merged) break;   // agar merge nahi hua to stop
        }
        
        return s;
    }
};