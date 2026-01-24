class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {

        int n = nums.size();

        int lsum = 0;   // left side ka sum (index i se pehle wale elements)
        int rsum = 0;   // right side ka sum (index i ke baad wale elements)

        // pehle pura array ka sum nikaal lo => initially rsum = totalSum
        for (int i = 0; i < n; i++) {
            rsum += nums[i];
        }

        // ab har index ko middle index maan ke check karenge
        for (int i = 0; i < n; i++) {

            // current element nums[i] ko right sum se hata do
            // ab rsum = sum of elements strictly right of i
            rsum = rsum - nums[i];

            // agar left sum == right sum => ye middle index hai
            if (lsum == rsum) return i;

            // current element ko left sum me add karo
            // next iteration me lsum = sum of elements strictly left of (i+1)
            lsum += nums[i];
        }

        // agar koi index match nahi mila
        return -1;
    }
};
