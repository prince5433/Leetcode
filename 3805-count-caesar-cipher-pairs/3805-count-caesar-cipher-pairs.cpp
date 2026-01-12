class Solution {
public:
    long long countPairs(vector<string>& words) {

        // Map to store frequency of each difference pattern
        // Key   : vector<int> representing cyclic differences
        // Value : number of strings having this pattern
        map<vector<int>, int> freq;

        long long ans = 0;   // total number of similar pairs

        // Step 1: Build difference pattern for each word
        for (auto w : words) {
            int m = w.size();
            vector<int> diff;

            // Calculate cyclic difference between consecutive characters
            for (int i = 1; i < m; i++) {
                int d = w[i] - w[i - 1];   // next - previous
                if (d < 0) d += 26;        // handle wrap-around (z -> a)
                diff.push_back(d);
            }

            // Increase frequency of this difference pattern
            freq[diff]++;
        }

        // Step 2: Count pairs using kC2 for each pattern group
        for (auto it : freq) {
            long long k = it.second;
            ans += k * (k - 1) / 2;
        }

        return ans;   // return total number of similar pairs
    }
};
