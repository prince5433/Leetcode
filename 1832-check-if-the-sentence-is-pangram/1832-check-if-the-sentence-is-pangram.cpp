class Solution {
public:
    bool checkIfPangram(string sentence) {

        int n = sentence.size();

        // unordered_map to store frequency of each character
        unordered_map<char, int> mp;

        // Count frequency of each character in sentence
        for(char c : sentence)
            mp[c]++;

        // Check if all characters from 'a' to 'z' are present
        for(char ch = 'a'; ch <= 'z'; ch++){

            // If any character is missing (frequency = 0)
            // then sentence is not a pangram
            if(mp[ch] == 0)
                return false;
        }

        // If all characters exist at least once
        return true;
    }
};
