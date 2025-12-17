class Solution {
public:
    int similarPairs(vector<string>& words) {
        int cnt = 0;                 // to count number of similar pairs
        int n = words.size();        // total number of words

        // Pick first word of the pair
        for(int i = 0; i < n - 1; i++){
            // Create a set of unique characters for words[i]
            set<char> s1(words[i].begin(), words[i].end());

            // Compare with all words after index i
            for(int j = i + 1; j < n; j++){
                // Create a set of unique characters for words[j]
                set<char> s2(words[j].begin(), words[j].end());

                // If both sets are equal, the pair is similar
                if(s1 == s2)
                    cnt++;
            }
        }

        return cnt;   // return total similar pairs
    }
};
