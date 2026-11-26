class Solution {
public:
    typedef long long ll;
    int MOD = 1e9 + 7;

    // Binary exponentiation: a^base % MOD calculate karta hai.
    // Har recursive call exponent ko half karta hai, isliye O(log base) time lagta hai.
    ll findPower(ll a, ll base) {
        if (base == 0) {
            return 1; // a^0 = 1
        }

        // Pehle a^(base/2) calculate karte hain.
        // Isse same power ko baar-baar calculate karne ki zarurat nahi padti.
        ll half = findPower(a, base / 2);

        // (a^k)^2 = a^(2k), yani half power ko square karna.
        ll result = (half * half) % MOD;

        // Agar exponent odd hai, toh ek extra 'a' multiply karna hoga.
        // Example: a^5 = (a^2)^2 * a
        if (base % 2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }

    bool check(vector<int>& nums, int size, int base) {
        int n = nums.size();
        unordered_map<ll, int> mp;

        int i = 0;
        int j = 0;

        // Rolling hash mein first element ka place-value:
        // Window size = size ho toh leftmost element ka weight base^(size-1) hota hai.
        // Window slide karte waqt isi value se leftmost element ka contribution remove hoga.
        ll p = findPower(base, size - 1);

        ll hash = 0;

        while (j < n) {
            // Naya element hash ke right side par add karte hain:
            // purane hash ko base se multiply karke nums[j] add hota hai.
            // Example: [a, b] ka hash -> a*base + b
            hash = (hash * base + nums[j]) % MOD;

            if (j - i + 1 < size) {
                // Abhi window ka size required size se chhota hai,
                // isliye next element add karne ke liye j aage badhao.
                j++;
            } else {
                // Ab window ka size exactly 'size' hai.
                // Is subarray ka hash frequency map mein store karo.
                // Same hash dobara aaya toh uski frequency increase hogi.
                mp[hash]++;

                // Next window banane ke liye leftmost element remove karo.
                // nums[i] * p us element ka hash mein contribution hai.
                // MOD add kiya hai taaki subtraction negative na rahe.
                hash = (hash - nums[i] * p % MOD + MOD) % MOD;

                // Window ko ek position right shift karo.
                i++;
                j++;
            }
        }

        // Agar kisi hash ki frequency exactly 1 hai,
        // toh us hash ke corresponding window ko unique maan rahe hain.
        for (auto& it : mp) {
            if (it.second == 1) {
                return true;
            }
        }

        // Koi hash exactly ek baar nahi aaya.
        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        // Base ko maximum element se bada rakha hai,
        // taaki different number sequences ke positional hashes alag ban sakein
        // (modulo collision ka risk phir bhi rehta hai).
        int base = *max_element(nums.begin(), nums.end()) + 1;

        // Possible subarray size 1 se n tak ho sakta hai.
        int l = 1;
        int r = n;
        int result = n;

        while (l <= r) {
            // Mid size check karo.
            // Ye form l + (r-l)/2, l+r se hone wale overflow se bachata hai.
            int mid = l + (r - l) / 2;

            if (check(nums, mid, base)) {
                // Is size par unique subarray mil gayi.
                // Answer ko update karke aur chhota size search karo.
                result = mid;
                r = mid - 1;
            } else {
                // Is size par unique subarray nahi mili,
                // toh larger size try karte hain.
                l = mid + 1;
            }
        }

        return result;
    }
};