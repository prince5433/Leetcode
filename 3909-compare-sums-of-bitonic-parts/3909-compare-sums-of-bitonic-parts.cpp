class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;   // this will store index of peak element

        // Step 1: Find the peak of bitonic array
        // Peak means element greater than both neighbours
        for(int i = 1; i < n - 1; i++) {
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                idx = i;
                break;
            }
        }

        long long asc = 0;   // sum of increasing part
        long long desc = 0;  // sum of decreasing part

        // Step 2: Calculate sum from start till peak (inclusive)
        for(int i = 0; i <= idx; i++) {
            asc += nums[i];
        }

        // Step 3: Calculate sum from peak till end (inclusive)
        for(int i = idx; i < n; i++) {
            desc += nums[i];
        }

        // Step 4: Compare both sums and return answer
        if(asc > desc) return 0;      // increasing side has larger sum
        else if(desc > asc) return 1; // decreasing side has larger sum
        else return -1;               // both sums are equal
    }
};