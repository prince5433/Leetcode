class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        // Step 1: Remainders ke basis par numbers ko buckets mein divide karein.
        // Kisi bhi 3 numbers ka sum 3 se tabhi divide hoga jab unke remainders ka sum bhi 3 se divide ho.
        vector<int> r0, r1, r2;
        for (int num : nums) {
            if (num % 3 == 0) r0.push_back(num);
            else if (num % 3 == 1) r1.push_back(num);
            else r2.push_back(num);
        }

        // Step 2: Har group ko descending order (bade se chota) mein sort karein.
        // Humein "Maximum Sum" chahiye, isliye hum har group ke sabse bade elements uthayenge.
        sort(r0.rbegin(), r0.rend());
        sort(r1.rbegin(), r1.rend());
        sort(r2.rbegin(), r2.rend());

        long long maxi = 0; // Sum store karne ke liye long long use karna safe hai.

        // Step 3: Char (4) possible cases check karein jahan sum % 3 == 0 hota hai:

        // Case A: Teeno numbers remainder 0 wale ho (0 + 0 + 0 = 0)
        if (r0.size() >= 3) {
            maxi = max(maxi, (long long)r0[0] + r0[1] + r0[2]);
        }
        
        // Case B: Teeno numbers remainder 1 wale ho (1 + 1 + 1 = 3, jo 3 se divisible hai)
        if (r1.size() >= 3) {
            maxi = max(maxi, (long long)r1[0] + r1[1] + r1[2]);
        }
        
        // Case C: Teeno numbers remainder 2 wale ho (2 + 2 + 2 = 6, jo 3 se divisible hai)
        if (r2.size() >= 3) {
            maxi = max(maxi, (long long)r2[0] + r2[1] + r2[2]);
        }
        
        // Case D: Teeno groups se ek-ek number ho (0 + 1 + 2 = 3, jo 3 se divisible hai)
        // Note: Yahan size >= 1 check karna zaroori hai crash se bachne ke liye.
        if (r0.size() >= 1 && r1.size() >= 1 && r2.size() >= 1) {
            maxi = max(maxi, (long long)r0[0] + r1[0] + r2[0]);
        }

        // Step 4: Final maximum sum return karein. Agar koi triplet nahi mila toh 0 aayega.
        return maxi;
    }
};