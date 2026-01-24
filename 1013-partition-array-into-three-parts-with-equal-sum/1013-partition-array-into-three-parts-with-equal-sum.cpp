class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& nums) {

        // total sum of array
        int total = accumulate(nums.begin(), nums.end(), 0);

        // agar total 3 se divisible nahi hai => 3 equal parts possible hi nahi
        if (total % 3 != 0) return false;

        int parts = 0;   // kitne parts ka sum = target mila
        int sum = 0;     // current running sum
        int n = nums.size();

        // har part ka required sum
        int target = total / 3;

        // left to right scan
        for (int i = 0; i < n; i++) {
            sum += nums[i];   // element add karte jao

            // jab sum target ke equal ho jaye => ek part complete
            if (sum == target) {
                parts++;      // part count increase
                sum = 0;      // next part ke liye sum reset
            }
        }

        // agar 3 ya zyada parts mil gaye => true
        // (kyuki target=0 ho to extra parts bhi ban sakte hain)
        return parts >= 3;
    }
};
