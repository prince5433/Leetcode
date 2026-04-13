

class Solution {
public:
    // 🔹 Frequency of the smallest character nikalne ka optimized helper
    int getFreq(string &s) {
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;
        
        // Pehla char jo 0 se bada hai, wahi lexicographically smallest hai
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) return count[i];
        }
        return 0;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        /* =======================================================================
            🚀 OPTIMIZATION STEPS:
            1. 'words' ki saari frequencies pre-calculate karo.
            2. Unhe sort karo taaki Binary Search laga sakein.
            3. Har query ke liye upper_bound se wo position dhoondo jaha se 
               bade elements shuru ho rahe hain.
           =======================================================================
        */
        
        vector<int> wordFreqs;
        for (string &w : words) {
            wordFreqs.push_back(getFreq(w));
        }
        
        // 🔹 Step 1: Sorting (Mandatory for Binary Search)
        sort(wordFreqs.begin(), wordFreqs.end());

        int n = queries.size();
        vector<int> ans(n);

        // 🔹 Step 2: Binary Search for each query
        for (int i = 0; i < n; i++) {
            int fq = getFreq(queries[i]);
            
            /* 🔥 THE TRICK: 
               upper_bound() humein us pehle element ka iterator dega jo 'fq' se BADA hai.
               Total size mein se us index ko minus karne par humein count mil jayega.
            */
            auto it = upper_bound(wordFreqs.begin(), wordFreqs.end(), fq);
            
            // Kitne elements 'it' se end tak bache?
            ans[i] = wordFreqs.end() - it;
        }

        return ans;
    }
};