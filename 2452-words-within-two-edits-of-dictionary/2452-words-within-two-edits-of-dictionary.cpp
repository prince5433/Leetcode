class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        // iterate over each query word
        for(auto &q : queries){

            // try matching with every dictionary word
            for(auto &d : dictionary){

                int diff = 0; // count mismatched characters

                // compare character by character
                for(int i = 0; i < d.length(); i++){
                    if(q[i] != d[i]) diff++;

                    // if more than 2 mismatches, stop early
                    if(diff > 2) break;
                }

                // if valid match found (<=2 edits)
                if(diff <= 2){
                    ans.push_back(q); // add query to result
                    break; // no need to check other dictionary words
                }
            }
        }

        return ans;
    }
};