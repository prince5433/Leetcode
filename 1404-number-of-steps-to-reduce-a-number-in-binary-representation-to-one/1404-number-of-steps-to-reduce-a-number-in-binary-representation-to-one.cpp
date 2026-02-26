class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int ops = 0;      // total operations count
        int car = 0;      // carry generated after +1 operation
        
        // right se left iterate kar rahe hain
        // i >= 1 kyunki MSB (index 0) ko process nahi karte
        for(int i = n - 1; i >= 1; i--) {
            
            // current bit + carry check karte hain
            if(((s[i] - '0') + car) % 2 == 1) {
                
                // odd number:
                // pehle +1 karna padega (1 step)
                // phir divide by 2 (1 step)
                ops += 2;
                
                // +1 karne par carry generate hoga
                car = 1;
            } 
            else {
                
                // even number:
                // sirf divide by 2 (1 step)
                ops += 1;
            }
        }
        
        // agar last me carry bacha hai
        // to ek extra step lagega
        return ops + car;
    }
};