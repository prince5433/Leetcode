class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();              // array ka size n

        sort(nums.begin(), nums.end());   // array ko ascending order me sort kar diya

        for(int i = 0; i < n; i++) {
            int x = n - i;                // x = number of elements from index i to end

            // condition:
            // nums[i] >= x  -> i se end tak sab elements >= x ho sakte hain
            // nums[i-1] < x -> i se pehle wale elements x se chhote hone chahiye
            if(nums[i] >= x && (i == 0 || nums[i-1] < x))
                return x;                 // special value mil gayi
        }

        return -1;                        // koi bhi x valid nahi mila
    }
};
