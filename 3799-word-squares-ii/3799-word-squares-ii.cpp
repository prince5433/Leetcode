class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();              // total number of words
        vector<vector<string>> ans;        // store all valid word squares

        // i -> top word
        for(int i = 0; i < n; i++) {

            // j -> left word
            for(int j = 0; j < n; j++) {
                if(i == j) continue;       // words must be distinct

                // k -> right word
                for(int k = 0; k < n; k++) {
                    if(k == i || k == j) continue;

                    // l -> bottom word
                    for(int l = 0; l < n; l++) {
                        if(l == i || l == j || l == k) continue;

                        // Check the 4 corner constraints
                        if(words[i][0] == words[j][0] &&   // top[0] == left[0]
                           words[i][3] == words[k][0] &&   // top[3] == right[0]
                           words[l][0] == words[j][3] &&   // bottom[0] == left[3]
                           words[l][3] == words[k][3]) {  // bottom[3] == right[3]

                            // Valid word square found
                            ans.push_back({
                                words[i],    // top
                                words[j],    // left
                                words[k],    // right
                                words[l]     // bottom
                            });
                        }
                    }
                }
            }
        }

        // Sort result lexicographically as required
        sort(ans.begin(), ans.end());

        return ans;
    }
};
