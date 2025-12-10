class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        // Step 1: Find GCD of all elements in numsDivide
        // Because final remaining number in nums must divide this GCD
        int g = numsDivide[0];
        int n = numsDivide.size();

        for(int i = 1; i < n; i++){
            g = gcd(g, numsDivide[i]);   // cumulative GCD
        }

        // Step 2: Sort nums so we check smallest numbers first
        // Because deleting smallest costs minimum deletions
        sort(nums.begin(), nums.end());

        // Step 3: Find the first number in nums which divides g
        // That number is the one we want to keep (minimum deletions = its index)
        for(int i = 0; i < nums.size(); i++){
            if(g % nums[i] == 0)         // nums[i] divides gcd → valid candidate
                return i;                // i elements smaller than nums[i] must be deleted
        }

        // If no number divides g → impossible
        return -1;
    }
};
