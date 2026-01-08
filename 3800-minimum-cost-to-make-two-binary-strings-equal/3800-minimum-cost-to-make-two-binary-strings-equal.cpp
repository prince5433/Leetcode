class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        long long a = 0, b = 0;
        
        // Step 1: Count mismatches
        // a = count of positions where s[i]='0' and t[i]='1'
        // b = count of positions where s[i]='1' and t[i]='0'
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0' && t[i] == '1') a++;
            else if (s[i] == '1' && t[i] == '0') b++;
        }

        // Step 2: Pair opposite mismatches
        long long p = min(a, b);  // max pairs of opposite mismatches
        long long cost = p * min((long long)swapCost, 2LL * flipCost);

        // Update remaining mismatches
        a -= p;
        b -= p;

        // Step 3: Fix remaining same-type mismatches
        long long r = abs(a - b);  // remaining mismatches of same type
        cost += (r / 2) * min((long long)crossCost + swapCost, 2LL * flipCost);

        // Step 4: If 1 mismatch remains, flip it
        if (r % 2 == 1) cost += flipCost;

        return cost;
    }
};
