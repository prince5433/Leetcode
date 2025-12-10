class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans; // Vector to store all simplified fractions

        // Loop over numerator (i) from 1 to n
        for(int i = 1; i <= n; i++){
            // Loop over denominator (j) from 2 to n
            for(int j = 2; j <= n; j++){
                // Only consider proper fractions (numerator < denominator)
                // and fractions that are simplified (gcd(i,j) == 1)
                if(i < j && __gcd(i, j) == 1){
                    // Convert fraction to string "i/j" and add to ans
                    ans.push_back(to_string(i) + "/" + to_string(j));
                }
            }
        }

        return ans; // Return the vector of simplified fractions
    }
};
