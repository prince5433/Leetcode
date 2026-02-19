class Solution {
public:
    vector<int> evenOddBit(int n) {
        
        string temp="";
        
        // Convert number to binary (LSB first)
        // Example: n = 10 → temp = "0101"
        while(n>0){
            temp+=to_string(n%2); // append last bit
            n/=2;                // remove last bit
        }
        
        int odd=0,even=0;
        
        // Traverse binary string
        // index 0 → even position (LSB)
        // index 1 → odd position
        for(int i=0;i<temp.length();i++){
            
            // if bit is 1 and position is even
            if(i%2==0 && temp[i]=='1') 
                even++;
            
            // if bit is 1 and position is odd
            if(i%2==1 && temp[i]=='1') 
                odd++;
        }
        
        // return result
        return {even,odd};
    }
};
