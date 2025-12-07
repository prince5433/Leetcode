class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        
        // Size of the input array
        int n = nums.size();
        
        // Counter to count how many even numbers are present in the array
        int ec = 0;

        // Loop through each number in the array
        for (int num : nums) {

            // If the number is even (i.e., divisible by 2)
            // then increment the even counter
            if (num % 2 == 0) ec++;
        }

        // If we have at least 2 even numbers,
        // then it is possible to create a number with trailing zeros after multiplication
        return ec >= 2;
    }
};
