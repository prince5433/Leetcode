class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {

        // Map to store frequency of each number
        map<int,int> mp;

        // Count frequency of every number in the array
        for(int num : nums)
            mp[num]++;

        int xore = 0;   // Variable to store XOR of duplicate numbers

        // Traverse the map
        for(auto it : mp) {

            // If a number appears exactly twice
            if(it.second == 2)
                xore ^= it.first;   // XOR the number with result
        }

        // Return final XOR value
        return xore;
    }
};
