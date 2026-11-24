class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        
        // Kisi bhi 2 numbers ke liye prod == lcm * gcd hamesha true hota hai,
        // isliye minimum answer 2 toh hoga hi (constraints me n >= 2 hai).
        int ans = 2;
        
        int i = 0; // Window ka start pointer
        int j = 0; // Window ka end pointer
        
        // Current valid window [i...j-1] ke saare elements ka product
        long long int prod = 1;
        
        while (j < n) {
            // Length >= 3 valid hone ke liye saare elements aapas me coprime (gcd == 1) hone chahiye.
            // Agar prod aur nums[j] me koi common factor hai (gcd != 1),
            // toh left se (i) elements hataate jao jab tak window wapas coprime na ho jaye.
            while (gcd(prod, nums[j]) != 1) {
                prod /= nums[i];
                i++;
            }
            
            // Ab nums[j] window ke kisi bhi element se common factor share nahi karta,
            // toh isko safely window me include kar lo.
            prod *= nums[j];
            
            // Current valid window ki length (j - i + 1) se max answer update karo.
            ans = max(ans, j - i + 1);
            
            // Next element pe move karo
            j++;
        }
        
        return ans;
    }
};