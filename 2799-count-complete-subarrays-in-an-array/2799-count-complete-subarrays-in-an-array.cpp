class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        int ans = 0;                 // Complete subarrays count karne ke liye
        int n = nums.size();         // Array ka size

        set<int> st;                 // Pure array ke distinct elements store karne ke liye

        for(int num : nums) 
            st.insert(num);          // Har element ko set me daal rahe hain

        int distinct = st.size();    // Total distinct elements in whole array

        for(int i = 0; i < n; i++){  // Subarray ka starting index fix kar rahe hain

            set<int> se;             // Current subarray ke distinct elements track karne ke liye

            for(int j = i; j < n; j++){  // Subarray extend kar rahe hain

                se.insert(nums[j]);      // Current element set me insert

                // Agar current subarray me utne hi distinct elements aa gaye
                // jitne pure array me hain -> complete subarray
                if(se.size() == distinct) 
                    ans++;
            }
        }

        return ans;                  // Total complete subarrays return
    }
};