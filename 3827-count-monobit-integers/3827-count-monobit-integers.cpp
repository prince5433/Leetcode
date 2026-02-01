class Solution {
public:
    // This function checks whether a number has all bits same (all 1s or 0)
    // Property used:
    // If x has binary form like 0, 1, 3, 7, 15 ... (all 1s),
    // then x & (x + 1) == 0
    // This also works for x = 0
    bool isMono(int x){
        return (x & (x + 1)) == 0;
    }

    // Counts how many numbers from 0 to n (inclusive)
    // have all bits same in their binary representation
    int countMonobit(int n) {
        int ans = 0;

        // Check every number from 0 to n
        for(int i = 0; i <= n; i++){
            // If i is a monobit number, increment count
            if(isMono(i)) ans++;
        }

        return ans;
    }
};
