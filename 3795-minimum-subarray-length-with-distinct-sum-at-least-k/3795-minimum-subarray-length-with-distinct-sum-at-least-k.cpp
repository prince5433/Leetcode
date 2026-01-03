class Solution {
public:
    int minLength(vector<int>& nums, int k) {

        unordered_map<int,int> freq; // har value ki frequency
        int ds = 0;                  // distinct elements ka sum
        int l = 0;                   // left pointer
        int ans = INT_MAX;           // minimum length store karega

        // right pointer se window expand karte hain
        for (int r = 0; r < nums.size(); r++) {

            // agar nums[r] pehli baar aa raha hai
            if (freq[nums[r]] == 0) {
                ds += nums[r];       // distinct sum me add
            }
            freq[nums[r]]++;         // frequency badhao

            // jab tak distinct sum >= k ho
            while (ds >= k) {
                ans = min(ans, r - l + 1); // answer update

                // left side se element hatao
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    ds -= nums[l];   // agar completely remove hua
                }
                l++;                 // window shrink
            }
        }

        // agar koi valid subarray nahi mila
        return ans == INT_MAX ? -1 : ans;
    }
};
