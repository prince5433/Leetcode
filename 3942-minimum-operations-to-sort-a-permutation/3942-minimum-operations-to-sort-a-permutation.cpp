class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        /* =========================================
        INTUITION (Logic ka Nichod):
        =========================================
        Array ko sort karne ke liye usme "Cycle" hona zaroori hai. 
        Agar cycle nahi hai, toh -1 return karna hai.
        
        Cycle do tarah ki ho sakti hai:
        1. ASCENDING CYCLE (Seedhi Cycle): e.g., [2, 3, 4, 0, 1]
           - Rasta A: Direct Left Rotate karte jao jab tak 0 first index pe na aaye.
           - Rasta B: Reverse -> Rotate -> Reverse (Ye Right Rotate karne ka hack hai).
           
        2. DESCENDING CYCLE (Ulti Cycle): e.g., [1, 0, 4, 3, 2]
           - Kyunki array ulta hai, ek Reverse (1 op) toh 100% karna hi padega.
           - Rasta A: Pehle Reverse karo, fir array seedha ban jayega toh Left Rotate karo.
           - Rasta B: Pehle Left Rotate karke 0 ko aisi jagah set karo ki Reverse marte hi wo index 0 par gir jaye.
        =========================================
        */
        
        // ans ko shuru me bahut badi value (infinity) di hai
        int ans = 1e9; 
        
        // STEP 1: Array mein '0' kis index par hai wo dhundho
        int pos0 = find(nums.begin(), nums.end(), 0) - nums.begin();

        // =========================================================
        // STEP 2: ASCENDING CYCLE (Seedhi Cycle) CHECK & CALCULATE
        // =========================================================
        bool isAscending = true;
        for (int i = 0; i < n; i++) {
            // (i - pos0 + n) % n -> ye formula batata hai ki har index 'i' pe kya value aani chahiye
            if (nums[i] != (i - pos0 + n) % n) {
                isAscending = false;
                break;
            }
        }

        // Agar array seedhi cycle mein hai
        if (isAscending) {
            // k = number of left rotations required to bring 0 to 0th index
            int k = pos0; 
            
            // min(k, n - k + 2) ka matlab:
            // k -> Sirf Left Rotate ka rasta
            // n - k + 2 -> Reverse (1 op) + Rotate (n-k ops) + Reverse (1 op) ka rasta
            ans = min(ans, min(k, n - k + 2)); 
        }

        // =========================================================
        // STEP 3: DESCENDING CYCLE (Ulti Cycle) CHECK & CALCULATE
        // =========================================================
        bool isDescending = true;
        for (int i = 0; i < n; i++) {
            // (pos0 - i + n) % n -> ye formula batata hai descending cycle me har index 'i' pe kya aana chahiye
            int expected = (pos0 - i + n) % n;
            if (nums[i] != expected) {
                isDescending = false;
                break;
            }
        }

        // Agar array ulti cycle mein hai
        if (isDescending) {
            // k ka matlab hai: "Agar main pehle Reverse kar du, toh '0' naye array me kis index par jayega?"
            int k = (n - 1 - pos0 + n) % n;
            //hr elemenet ko reverse krne se wo n-1-i pe aata haio to 0 n-1-pos pe aayagea
            //+n and % n to bs cycle handle krne k liye kiya gya hai
            
            // 1 + min(k, n - k) ka matlab:
            // 1 -> Ye ek 'Reverse' ka operation hai jo descending ko ascending banane ke liye karna hi padega
            // k -> Pehle Reverse kiya, fir left Rotate kiya
            // n - k -> Pehle Rotate kiya, fir end me ek Reverse mara
            ans = min(ans, 1 + min(k, n - k));
        }

        // =========================================================
        // STEP 4: FINAL RESULT
        // =========================================================
        // Agar dono cycles fail ho gayi toh impossible hai, -1 return karo
        return ans == 1e9 ? -1 : ans;
    }
};