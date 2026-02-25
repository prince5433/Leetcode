class Solution {
public:
    bool canSortArray(vector<int>& nums) {

        int n = nums.size();

        // Bubble sort approach use kar rahe hain
        // swapped check karega ki koi swap hua ya nahi
        bool swapped = true;

        for(int i = 0; i < n; i++) {

            swapped = false;  // har pass ke start me false

            for(int j = 0; j < n - i - 1; j++) {

                // agar already sorted hai to kuch mat karo
                if(nums[j] <= nums[j+1]) 
                    continue;

                else {
                    // agar left > right hai to swap karna padega
                    // lekin swap tabhi allowed hai jab
                    // dono numbers ke set bits equal ho
                    if(__builtin_popcount(nums[j]) == 
                       __builtin_popcount(nums[j+1])) {

                        swap(nums[j], nums[j+1]);
                        swapped = true;  // swap hua
                    }
                    else {
                        // agar popcount equal nahi hai
                        // aur swap required hai
                        // to sorting possible hi nahi
                        return false;
                    }
                }

                // agar inner loop me ek bhi swap nahi hua
                // to array already sorted hai
                if(swapped == false) 
                    break;
            }
        }

        // agar poora bubble process chal gaya
        // aur kahin false return nahi hua
        return true;
    }
};