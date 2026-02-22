class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        // Step 1: binary string banate hain
        string temp = "";
        
        while(n > 0){
            temp += to_string(n % 2);
            n /= 2;
        }
        
        // Step 2: 32-bit complete karne ke liye remaining 0 add karo
        while(temp.length() < 32){
            temp += '0';
        }
        
        // Ab temp already reversed binary hai
        // (kyunki hum LSB se build kar rahe the)
        
        // Step 3: Decimal me convert karo
        uint32_t ans = 0;
        
        for(int i = 0; i < 32; i++){
            ans = ans * 2 + (temp[i] - '0');
        }
        
        return ans;
    }
};