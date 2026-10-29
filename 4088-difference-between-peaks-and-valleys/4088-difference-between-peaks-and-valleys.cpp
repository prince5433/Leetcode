class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int n = nums.size();
        int psum = 0, vsum = 0;

        // First aur last index ko skip karo,
        // kyunki peak/valley ke dono neighbours hone chahiye.
        for (int i = 1; i < n - 1; i++) {

            // Peak: dono neighbours se strictly bada.
            if (nums[i] > nums[i - 1] &&
                nums[i] > nums[i + 1]) {
                psum += nums[i];
            }

            // Valley: dono neighbours se strictly chhota.
            else if (nums[i] < nums[i - 1] &&
                     nums[i] < nums[i + 1]) {
                vsum += nums[i];
            }
        }

        // Peak values ka sum - valley values ka sum.
        return psum - vsum;
    }
};

/*
TC: O(n) — har middle element ek baar check hota hai.
SC: O(1) — sirf sum variables use hote hain.
*/