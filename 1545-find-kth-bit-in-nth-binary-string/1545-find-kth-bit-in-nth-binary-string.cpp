class Solution {
public:
    
    // Recursive function to find kth bit in nth string
    char solve(int n, int k){
        
        // Base case:
        // S1 = "0"
        if(n == 1) 
            return '0';
        
        // Length of Sn = 2^n - 1
        int len = (1 << n) - 1;
        
        // Middle position (1-based indexing)
        int mid = (len / 2) + 1;
        
        // Case 1: If k is exactly middle
        // Middle element is always '1'
        if(k == mid) 
            return '1';
        
        // Case 2: If k is in left half
        // Left half is exactly same as Sn-1
        else if(k < mid) 
            return solve(n - 1, k);
        
        // Case 3: If k is in right half
        else {
            // Right half is reverse(invert(Sn-1))
            
            // Find mirrored index in left half
            // Because right half is reversed
            int mirror = len - k + 1;
            
            // Recursively get corresponding character
            char ch = solve(n - 1, mirror);
            
            // Invert the character
            // Because right half is inverted
            return (ch == '0') ? '1' : '0';
        }
    }
    
    char findKthBit(int n, int k) {
        return solve(n, k);
    }
};