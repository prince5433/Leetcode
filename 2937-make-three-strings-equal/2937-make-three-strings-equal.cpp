class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        
        int lcommonprefix = 0; // stores length of longest common prefix
        
        int i = 0, j = 0, k = 0; // pointers for s1, s2, s3
        
        // traverse all strings simultaneously
        while(i < s1.size() && j < s2.size() && k < s3.size()){
            
            // check if characters at current position are same
            if(s1[i] == s2[j] && s2[j] == s3[k]) {
                
                lcommonprefix++; // increase common prefix length
                
                // move to next characters
                i++;
                j++;
                k++;
            } 
            else break; // stop when mismatch occurs
        }
        
        // if no common prefix exists
        if(lcommonprefix == 0) return -1;
        
        // total deletions needed to make all strings equal to the prefix
        return (s1.size() - lcommonprefix) +
               (s2.size() - lcommonprefix) +
               (s3.size() - lcommonprefix);
    }
};