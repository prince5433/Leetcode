class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n = s.size(), m = goal.size();
        
        // Agar dono strings ki length alag hai
        // to rotation possible hi nahi hai
        if(n != m) return false;

        // Maximum n baar rotate karenge
        // kyunki n rotations ke baad string fir same ho jayegi
        for(int i = 0; i < n; i++) {
            
            char ch = s[0];      // pehla character store kar liya
            
            s.erase(0,1);        // 0th index se 1 character delete kar diya
                                // matlab first character hata diya
            
            s += ch;             // deleted character ko end me add kar diya
                                // ye ek left rotation ho gaya
            
            // Har rotation ke baad check karo
            // kya string goal ke equal ban gayi?
            if(s == goal) return true;
        }

        // Agar saari rotations ke baad bhi equal nahi bani
        return false;
    }
};