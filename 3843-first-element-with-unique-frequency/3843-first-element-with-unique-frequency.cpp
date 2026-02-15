class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {

        // Step 1: store frequency of each number
        unordered_map<int,int> freq;
        for(int num : nums)
            freq[num]++;

        // Step 2: store count of each frequency
        unordered_map<int,int> freqcnt;
        for(auto it : freq)
            freqcnt[it.second]++;

        // Step 3: traverse original array to get FIRST element
        for(int num : nums){

            // if its frequency occurs only once
            if(freqcnt[freq[num]] == 1)
                return num;
        }

        // if none found
        return -1;
    }
};
