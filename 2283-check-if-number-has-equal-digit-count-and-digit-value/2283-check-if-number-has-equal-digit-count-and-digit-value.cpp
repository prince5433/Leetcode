class Solution {
public:
    bool digitCount(string num) {
        int n = num.size();   // length of the string

        // freq[d] will store how many times digit 'd' appears in the string
        vector<int> freq(10, 0);

        // Count frequency of each digit in num
        for(char c : num){
            freq[c - '0']++;
        }

        // Check the condition:
        // At index i, digit i should appear exactly (num[i] - '0') times
        for(int i = 0; i < n; i++){
            if(freq[i] != num[i] - '0')
                return false;   // condition fails
        }

        return true;   // all conditions satisfied
    }
};
