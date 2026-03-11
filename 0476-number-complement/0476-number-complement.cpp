class Solution {
public:
    int findComplement(int n) {
  if(n==0) return 1; 
        // Special case: complement of 0 is 1

        string bin = bitset<32>(n).to_string(); 
        // Convert integer to 32-bit binary string

        int pos = bin.find('1'); 
        // Find the first '1' to remove leading zeros

        bin = bin.substr(pos); 
        // Keep only the significant bits

        for(char &c : bin){
            c = (c == '0') ? '1' : '0'; 
            // Flip each bit (0 → 1, 1 → 0)
        }

        return stoi(bin, 0, 2); 
        // Convert the flipped binary string back to decimal
    }
};