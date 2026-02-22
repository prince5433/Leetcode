class Solution {
public:
    string maximumXor(string s, string t) {
        
        int n = s.size();
        
        int co = 0, cz = 0;
        
        // Count number of '1's and '0's in string t
        for(char c : t){
            if(c == '1') co++;
            else cz++;
        }
        
        string temp = "";
        
        // Build a permutation of t greedily
        // To maximize XOR:
        // If s[i] = '1', best choice is '0'
        // If s[i] = '0', best choice is '1'
        for(char c : s){
            
            if(c == '1'){
                // Try to place '0' to get XOR = 1
                if(cz > 0){
                    temp += '0';
                    cz--;
                }
                else{
                    // If no '0' left, must place '1'
                    temp += '1';
                    co--;
                }
            }
            else{ // c == '0'
                // Try to place '1' to get XOR = 1
                if(co > 0){
                    temp += '1';
                    co--;
                }
                else{
                    // If no '1' left, must place '0'
                    temp += '0';
                    cz--;
                }
            }
        }
        
        // Build XOR result manually
        string ans = "";
        for(int i = 0; i < n; i++){
            if(s[i] == temp[i]) 
                ans += '0';   // Same bits → XOR = 0
            else 
                ans += '1';   // Different bits → XOR = 1
        }
        
        return ans;
    }
};