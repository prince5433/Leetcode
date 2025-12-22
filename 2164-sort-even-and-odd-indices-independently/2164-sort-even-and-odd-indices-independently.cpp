class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {

        vector<int> even, odd;   // store elements from even and odd indices

        // Separate elements based on index
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                even.push_back(nums[i]);  // even index
            else
                odd.push_back(nums[i]);   // odd index
        }

        // Sort even indices in increasing order
        sort(even.begin(), even.end());

        // Sort odd indices in decreasing order
        sort(odd.begin(), odd.end(), greater<int>());

        vector<int> ans;
        int i = 0, j = 0;

        // Merge back in index order
        while (i < even.size() || j < odd.size()) {
            if (i < even.size()) {
                ans.push_back(even[i]);
                i++;
            }
            if (j < odd.size()) {
                ans.push_back(odd[j]);
                j++;
            }
        }

        return ans;  // final sorted array
    }
};
