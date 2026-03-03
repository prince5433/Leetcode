class Solution {
public:
    int kthGrammar(int n, int k) {
        
        // Base case
        // First row has only one element: 0
        if(n == 1) 
            return 0;
        
        // Length of current row = 2^(n-1)
        int len = (1 << (n - 1));
        
        // Middle index divides left & right half
        int mid = len / 2;
        
        // If k lies in left half
        // It is exactly same as previous row
        if(k <= mid) 
            return kthGrammar(n - 1, k);
        
        // If k lies in right half
        // It is flipped version of corresponding left element
        else 
            return 1 - kthGrammar(n - 1, k - mid);
    }
};