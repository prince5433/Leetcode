class Solution {
public:
    int kthGrammar(int n, int k) {
        
        // Base case:
        // First row is always "0"
        if(n == 1) 
            return 0;
        
        // If k is even
        if(k % 2 == 0) {
            
            // Even position means it came from
            // second child of parent
            // Parent index = k/2
            
            int prevAns = kthGrammar(n - 1, k / 2);
            
            // Even child is always FLIPPED version of parent
            // 0 -> 1
            // 1 -> 0
            if(prevAns == 0) 
                return 1;
            else 
                return 0;
        } 
        else { 
            // If k is odd
            
            // Odd position means it came from
            // first child of parent
            // Parent index = k/2 + 1
            
            int prevAns = kthGrammar(n - 1, k / 2 + 1);
            
            // Odd child is SAME as parent
            return prevAns;
        }
    }
};