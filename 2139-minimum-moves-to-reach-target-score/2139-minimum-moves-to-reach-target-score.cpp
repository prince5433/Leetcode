class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ops = 0;   // total operations performed
        
        // agar doubling allowed hi nahi hai,
        // to sirf (target - 1) times -1 karna padega
        if(maxDoubles == 0) 
            return target - 1;
        
        // reverse process: target se 1 tak aate hain
        while(target != 1) {
            
            // agar number even hai
            if(target % 2 == 0) {
                
                // aur doubling operation available hai
                if(maxDoubles > 0) {
                    
                    // divide by 2 karte hain
                    // kyunki forward me multiply by 2 hua hoga
                    target /= 2;
                    
                    ops++;          // ek operation
                    maxDoubles--;   // ek double use ho gaya
                } 
                else {
                    
                    // doubling khatam ho chuki hai
                    // ab sirf -1 hi option hai
                    target -= 1;
                    ops++;
                }
            } 
            else {
                
                // agar odd hai to pehle -1 karna padega
                // kyunki odd ko directly divide nahi kar sakte
                target -= 1;
                ops++;
            }
        }
        
        return ops;
    }
};