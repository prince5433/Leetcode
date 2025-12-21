class Solution {
public:
    long long lastInteger(long long n) {
        long long head = 1;
        long long step = 1;
        long long rem = n;
        bool ltor = true;

        while (rem > 1) {
            // Right to Left aur Even count par hi head shift hota hai
            if (!ltor && rem % 2 == 0) {
                head += step;
            }

            // Important: Jab hum har 2nd element udate hain, 
            // toh hamesha (rem / 2) elements delete hote hain.
            // Jo bachte hain wo hain: rem - (rem / 2)
            rem = rem- (rem / 2);
            
            // Gap hamesha double hota hai
            step *= 2;
            
            // Direction switch
            ltor = !ltor;
        }
        return head;
    }
};