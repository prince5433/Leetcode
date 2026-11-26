class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10;
        int step = 0;

        while (take > 0 && n >= take) {
            n -= take;  // Current player required stones le raha hai
            take--;     // Agle turn mein required stones 1 kam honge
            step++;     // Ek successful turn complete hua
        }

        return step % 2 == 1; // Odd turns: Alice, even turns: Bob
    }
};