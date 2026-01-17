class Solution {
public:
bool allZero(vector<int>& count) {
        return count == vector<int>(26, 0);
    }
    vector<int> findAnagrams(string s, string p) {
          vector<int> ans;
            int k = p.size();                 // window size = pattern length
	    int n = s.size();                 // text length
	    
	    vector<int> count(26, 0);           // frequency array for 'a' to 'z'
	    
	    // Step 1: Fill count[] with pattern frequencies
	    // Example: pat = "for"
	    // count[f]++, count[o]++, count[r]++
	    for(char &ch : p) {
	        count[ch - 'a']++;
	    }

	    int i = 0, j = 0;                   // i = window start, j = window end
	    int result = 0;                     // number of anagrams found

	    // Step 2: Sliding window over txt
	    while(j < n) {
	        // Include txt[j] in the window
	        int idx = s[j] - 'a';
	        count[idx]--;                   // window me character add hua => requirement decrease

	        // Step 3: If window size becomes equal to k
	        if(j - i + 1 == k) {

	            // If all counts become zero => anagram found
	            if(allZero(count)) {
	               ans.push_back(i);
	            }

	            // Step 4: Remove txt[i] from the window (slide window forward)
	            // outgoing character ko undo karna
	            count[s[i] - 'a']++;      // window se character remove => requirement increase back
	            i++;                        // move window start
	        }

	        j++;                            // move window end
	    }

	    return ans;
	}
};
