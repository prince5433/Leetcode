class Solution {
public:
    typedef long long ll;
    int MOD = 1e9 + 7;

    // a^base % MOD calculate karta hai using binary exponentiation
    ll findPower(ll a, ll base) {
        if (base == 0) {
            return 1;
        }

        ll half = findPower(a, base / 2);

        // a^(base/2) ko square karke power ka half part banate hain
        ll result = (half * half) % MOD;

        // Odd exponent mein ek extra 'a' multiply karna hota hai
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

        // Window ke first element ka place-value: base^(size-1)
        ll p = findPower(base, size - 1);
        ll hash = 0;

        while (j < n) {
            // Current element ko rolling hash mein add karo
            hash = (hash * base + nums[j]) % MOD;

            if (j - i + 1 < size) {
                // Window abhi required size se chhoti hai
                j++;
            } else {
                // Fixed-size window ka hash frequency map mein store karo
                mp[hash]++;

                // Leftmost element ka contribution remove karo
                hash = (hash - nums[i] * p % MOD + MOD) % MOD;

                i++;
                j++;
            }
        }

        // Koi hash exactly ek baar aaya, toh unique window mil gayi
        for (auto& it : mp) {
            if (it.second == 1) {
                return true;
            }
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        // Base ko maximum element se bada rakha hai
        int base = *max_element(nums.begin(), nums.end()) + 1;

        int l = 1;
        int r = n;
        int result = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(nums, mid, base)) {
                result = mid; // Valid size mila, smaller size search karo
                r = mid - 1;
            } else {
                l = mid + 1; // Is size par unique window nahi mili
            }
        }

        return result;
    }
};