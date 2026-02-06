class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();          // Array ka size store kar liya

        int i = 0;                    // Pointer start se rakha
        while (i < n - 1) {           // Last se ek pehle tak check karenge
            if (nums[i] == nums[i + 1]) {
                // Agar current element aur next element same hain
                // to aage badho
                i++;
            } else {
                // Jaise hi koi adjacent element different mila
                // loop tod do
                break;
            }
        }

        // Agar i last index tak pahunch gaya
        // matlab saare elements same the
        if (i == n - 1) 
            return 0;                 // Koi operation nahi chahiye
        else 
            return 1;                 // Kam se kam 1 operation lagega
    }
};
