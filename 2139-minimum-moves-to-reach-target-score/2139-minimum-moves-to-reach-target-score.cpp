class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ops = 0;   // total operations count
        if(maxDoubles==0) return target-1;
        
        // jab tak target 1 nahi ho jata
        while(target != 1) {
            
            // agar target even hai
            if(target % 2 == 0) {
                
                // aur doubling operation available hai
                if(maxDoubles > 0) {
                    
                    // reverse thinking:
                    // originally multiply by 2 hua hoga
                    // isliye yaha divide kar dete hain
                    target /= 2;
                    
                    ops++;          // ek operation count
                    maxDoubles--;   // ek double use ho gaya
                } 
                else {
                    
                    // agar double use nahi kar sakte
                    // to sirf -1 karna padega
                    target -= 1;
                    ops++;
                }
            } 
            else {
                
                // agar target odd hai
                // to pehle -1 karna hi padega
                target -= 1;
                ops++;
            }
        }
        
        return ops;
    }
};